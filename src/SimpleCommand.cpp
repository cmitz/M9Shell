#include <iostream>
#include <unistd.h>
#include "SimpleCommand.h"

//    std::string              command;
//    std::vector<std::string> arguments;
//    std::vector<IORedirect>  redirects;

void SimpleCommand::execute() {
    if (command == "pwd") {
        pwd();
        return;
    }

    if (command == "cd") {
        cd();
        return;
    }
}

/**
 * Built-in command `pwd` that tells us the current working directory
 * Returns nothing
 */
void SimpleCommand::pwd() {
    char cwd[256];
    if (getcwd(cwd, sizeof(cwd)) == nullptr) {
        std::cerr << "getcwd() error" << std::endl;
    }
    else {
        std::cout << cwd << std::endl;
    }
}

/**
 * Built-in command `cd` that changes working directory
 * @param arguments
 */
void SimpleCommand::cd() {
    if (arguments.empty()) {
        char *home;
        home = getenv("HOME");

        chdir(home);
        pwd();
        return;
    }
};
