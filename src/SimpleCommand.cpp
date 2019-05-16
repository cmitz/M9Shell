#include <iostream>
#include <unistd.h>
#include "SimpleCommand.h"

//    std::string              command;
//    std::vector<std::string> arguments;
//    std::vector<IORedirect>  redirects;

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

    // Command was not a built-in command, must be a program
    // Convert arguments
    std::vector<char *> argsc;
    argsc.reserve(arguments.size() + 2);
    argsc.push_back(const_cast<char *>(command.c_str()));
    for(std::string const arg : arguments)
        argsc.push_back(const_cast<char *>(arg.c_str()));
    argsc.push_back(nullptr);

    // Fork this process
    pid_t cid;
    cid = fork();
    int returnValue = 0;

    switch (cid) {
        case -1: std::cerr << "Error forking" << std::endl;
            break;
        case 0: // This is the child process
            execvp(command.c_str(), argsc.data());
            exit(EXIT_SUCCESS);

            // This is the parent process
        default: waitpid(cid, &returnValue, 0);
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
