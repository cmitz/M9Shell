#include <iostream>
#include <unistd.h>
#include "SimpleCommand.h"

//    std::string              command;
//    std::vector<std::string> arguments;
//    std::vector<IORedirect>  redirects;

void SimpleCommand::execute() {
    if (command == "exit") {
        exit(0);
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

    // Command was not a built-in command
    // TODO: check if command is a path to a local executable

    pid_t cpid;
    cpid = fork();
    int returnValue;

    switch (cpid) {
        case -1: std::cerr << "Error forking" << std::endl;
            break;
        // This is the child process
        case 0:
            execl(command.c_str(), nullptr); // command.c_str()
            _exit (EXIT_FAILURE);
        // This is the parent process
        default: waitpid(cpid, &returnValue, 0);
    }

    std::cout << "Program " << command << " exited with " << returnValue << std::endl;
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
        std::cout << pwd() << std::endl;
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
};
