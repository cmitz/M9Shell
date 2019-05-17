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
 * Executes the commands on this pipeline.
 */
void Pipeline::execute() {
    if (commands.size() == 2) {
        // Create Pipe
        int fd[2];
        pipe(fd);

        int returnValue = 0;

        // Fork this process
        pid_t cid = fork();
        switch (cid) {
            case -1:
                std::cerr << "Error forking" << std::endl;
                exit(-1);
            case 0: // Child A process: writing into pipe
                close(fd[0]); // Do not care about pipe output

                dup2(fd[1], 1); // Replace stdout with pipe
                commands[0]->execute();
                exit(EXIT_SUCCESS);

            default: // Parent process: spawn another child for the reading
                // Fork this process
                pid_t cid2 = fork();
                switch(cid2) {
                    case -1:
                        std::cerr << "Error forking" << std::endl;
                        exit(-1);
                    case 0: // Child B process: read from pipe
                        close(fd[1]); // Do not care about pipe input

                        dup2(fd[0], 0); // Replace stdin with pipe
                        commands[1]->execute();
                        exit(EXIT_SUCCESS);

                    default: // Parent process: Don't bother about pipe, wait for child
                        close(fd[0]); // Do not care about pipe output
                        close(fd[1]); // Do not care about pipe input
                        waitpid(cid2, &returnValue, 0);
                }
        }
    } else {
        for( SimpleCommand *cmd : commands ) {
            // FIXME: Probably need to set up some pipe here?

            cmd->execute();
        }
    }

}