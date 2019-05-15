#include <iostream>
#include <unistd.h>
#include "SimpleCommand.h"

void SimpleCommand::execute() {
//    std::string              command;
//    std::vector<std::string> arguments;
//    std::vector<IORedirect>  redirects;

    // Built-in command PWD that tells us the current working directory
    if (command == "pwd") {
        char cwd[256];
        if (getcwd(cwd, sizeof(cwd)) == nullptr)
            std::cerr << "getcwd() error" << std::endl;
        else
            std::cout << cwd << std::endl;
    }
}
