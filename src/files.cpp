#include "files.hpp"
#include "ansi.hpp"
#include "getMenuChoice.cpp"
#include "debugConsole.hpp"

#include <fstream>
#include <iostream>
#include <string>

void files::Files::parseVersesTXT() {
    debug_console::DebugConsole::elements.push_back("Started parsing verses.txt");
    std::ifstream file("verses.txt");
    if (file.is_open()) {
        debug_console::DebugConsole::elements.push_back("File verses.txt is good");
        while (file.good()) {
            std::string line;
            std::getline(file, line);
            files::Files::verses.push_back(line);
        }
    } else {
        std::cout << ansi::ANSI_RED << "FATAL ERROR. CANNOT FIND OR READ FILE NAMED VERSES.TXT" << ansi::ANSI_RESET << std::endl;
        std::cout << ansi::ANSI_RED << "PLEASE CHECK THAT THE FILE EXISTS WITHIN THE SAME DIRECTORY AS MAIN.EXE AND CHECK FILE PERMISSIONS" << ansi::ANSI_RESET << std::endl;
        menu_choices::getStringChoice("PRESS ENTER TO ABORT.");
        exit(0);
    }
}