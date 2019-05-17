#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include "SimpleCommand.h"

void SimpleCommand::execute() {
    if (command == "exit") {
        exit(EXIT_SUCCESS);
    }

    if (command == "pwd") {
        std::cout << pwd() << std::endl;
        return;
    }

    if (command == "cd") {
        cd();
        std::cout << pwd() << std::endl;
        return;
    }

    program();
}

/**
 * Built-in command `pwd` that tells us the current working directory
 * Returns nothing
 */
std::string SimpleCommand::pwd() {
    char cwd[256];
    if (getcwd(cwd, sizeof(cwd)) == nullptr) {
        std::cerr << "getcwd() error" << std::endl;
    }
    else {
        return cwd;
    }
}

/**
 * Built-in command `cd` that changes working directory
 * @param arguments
 */
void SimpleCommand::cd() {
    if (arguments.empty() || arguments[0] == "~") {
        char *home = getenv("HOME");

        chdir(home);
        return;
    } else {
        // Get current path
        char path[256];
        strcpy(path, pwd().c_str());

        // Add trailing slash
        strcat(path, "/");
        strcat(path, arguments[0].c_str());

        // Change dir to path
        chdir(path);
    }
}

/**
 * Execute whatever command has been given as a program
 * Exits the spawned child process!
 * E.g. echo "hoi" >> helloworld
 */
void SimpleCommand::program() {
    // Convert arguments to char* so we can supply that to execvp
    std::vector<char *> argsc;
    argsc.reserve(arguments.size() + 2);
    argsc.push_back(const_cast<char *>(command.c_str()));

    for(std::string const &arg : arguments)
        argsc.push_back(const_cast<char *>(arg.c_str()));
    argsc.push_back(nullptr);

    // Fork this process
    pid_t cid;
    cid = fork();
    int returnValue = 0;

    // Execute program
    switch (cid) {
        case -1:
            std::cerr << "Error forking" << std::endl;
            exit(-1);
        case 0: // This is the child process

            redirectInputs();
            execvp(command.c_str(), argsc.data()); // Replace current process with command process
            exit(EXIT_SUCCESS);

        default: waitpid(cid, &returnValue, 0); // This is the parent process
    }

    std::cout << "Program " << command << " exited with status code " << returnValue << "." << std::endl;
}

void SimpleCommand::redirectInputs() {
    if (!redirects.empty()) {
        for (IORedirect const &red : redirects) {
            //TODO: &1 operators, e.g. `./outputs > out.txt 2>&1`
            int flags;
            switch(red.getType()) {
                case IORedirect::Type::APPEND: flags = O_CREAT|O_RDWR|O_APPEND;
                    break;
                case IORedirect::Type::OUTPUT: flags = O_CREAT|O_TRUNC|O_WRONLY;
                    break;
                case IORedirect::Type::INPUT:
                default: flags = O_CREAT|O_RDONLY;
                    break;
            }
            int fd = open(red.getNewFile().c_str(), flags, 0664);
            dup2(fd, red.getOldFileDescriptor());
        }
    }
}
