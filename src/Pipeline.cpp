#include <iostream>
#include <zconf.h>
#include "Pipeline.h"
#include "SimpleCommand.h"

/**
 * Destructor.
 */
Pipeline::~Pipeline() {
	for( SimpleCommand *cmd : commands )
		delete cmd;
}

/**
 * Executes the commands on this pipeline. Multiple pipes should look like this:
 * cmd0    cmd1   cmd2   cmd3   cmd4
 *    pipe0   pipe1  pipe2  pipe3
 *    [0,1]   [2,3]  [4,5]  [6,7]
 */
void Pipeline::execute() {
    // Use symbolic constants instead of magic numbers for readability
    const int PIPE_READ = 0;
    const int PIPE_WRITE = 1;

    // If only one command, simply execute it
    if (commands.size() == 1) {
        commands[0]->execute();
    } else {

        // Keep reference of the pipes between commands
        int new_pipefd[2];
        int old_pipefd[2];

        int commandCounter = 1; // Start on 1, because comparing to commands.size instead of index
        // Iterate over commands
        for( SimpleCommand *cmd : commands ) {

            bool isNotFirstCommand = commandCounter > 1;
            bool isNotLastCommand = commandCounter < commands.size();

            // If not last command, create pipe
            if (isNotLastCommand) {
                // Create Pipe
                pipe(new_pipefd);
            }

            // Fork this process
            pid_t cid = fork();
            switch (cid) {
                case -1: std::cerr << "Error forking" << std::endl; exit(-1);
                case 0: // Child A process
                    if (isNotFirstCommand) {                // There is a previous command, read from old pipe
                        dup2(old_pipefd[PIPE_READ], 0);     // Replace stdin
                        close(old_pipefd[PIPE_READ]);       // Close pipe
                        close(old_pipefd[PIPE_WRITE]);      // Close pipe
                    }
                    if (isNotLastCommand) {                 // There is a next command, write to new pipe
                        close(new_pipefd[PIPE_READ]);       // Don't need the read end
                        dup2(new_pipefd[PIPE_WRITE], 1);    // Replace stdout
                        close(new_pipefd[PIPE_WRITE]);      // Close pipe out
                    }

                    cmd->execute();                         // Execute command
                    exit(EXIT_SUCCESS);                     // Exit process

                default: // Parent process
                    // Fork this process
                    if (isNotFirstCommand) {
                        close(old_pipefd[PIPE_READ]);
                        close(old_pipefd[PIPE_WRITE]);
                    }
                    if (isNotLastCommand) {
                        old_pipefd[PIPE_READ] = new_pipefd[PIPE_READ];
                        old_pipefd[PIPE_WRITE] = new_pipefd[PIPE_WRITE];
                    }

                    // Wait for child process!
                    waitpid(cid, nullptr, 0);

                // End default
            } // End switch
            commandCounter++;
        } // End for
        // Close remaining pipes
        close(old_pipefd[PIPE_READ]);
        close(old_pipefd[PIPE_WRITE]);
    }
}