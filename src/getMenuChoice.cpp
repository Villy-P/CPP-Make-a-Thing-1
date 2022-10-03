#ifndef SRC_GETMENUCHOICE_CPP
#define SRC_GETMENUCHOICE_CPP

#include "getMenuChoice.hpp"
#include "debugConsole.hpp"

#include <string>
#include <iostream>
#include <regex>

unsigned char menu_choices::getMenuChoice(std::string prompt, int maxValue) {
    debug_console::DebugConsole::elements.push_back("Get Menu Choice Initialized");
    while (true) {
        std::cout << prompt;
        std::cout.flush();
        debug_console::DebugConsole::elements.push_back("Console Flushed");
        std::string input;
        std::getline(std::cin, input);
        if (std::regex_match(input, std::regex("[+]?[0-9]*"))) {
            debug_console::DebugConsole::elements.push_back("Match found");
            int value = std::stoi(input);
            if (value < 0 || value > maxValue) {
                debug_console::DebugConsole::elements.push_back("Value out of range");
                continue;
            }
            debug_console::DebugConsole::elements.push_back("Value works");
            return value;
        } else if (input == "") {
            debug_console::DebugConsole::elements.push_back("Enter pressed, returning 0");
            return 0;
        } else {
            debug_console::DebugConsole::elements.push_back("Invalid input, unknown reason.");
            continue;
        }
    }
    return 0;
}

std::string menu_choices::getStringChoice(std::string prompt) {
    debug_console::DebugConsole::elements.push_back("Get String Choice Initialized");
    std::string returnString;
    std::cout << prompt;
    std::getline(std::cin, returnString);
    debug_console::DebugConsole::elements.push_back("Get String Choice Success");
    return returnString;
}

#endif