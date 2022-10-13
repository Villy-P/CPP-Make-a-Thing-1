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

void files::Files::parseBetterDreams() {
    debug_console::DebugConsole::elements.push_back("Started parsing betterDreams.txt");
    std::ifstream file("betterDreams.txt");
    if (file.is_open()) {
        debug_console::DebugConsole::elements.push_back("File betterDreams.txt is good");
        while (file.good()) {
            std::string line;
            std::getline(file, line);
            files::Files::dreams.push_back(line);
        }
    } else {
        std::cout << ansi::ANSI_RED << "FATAL ERROR. CANNOT FIND OR READ FILE NAMED BETTERDREAMS.TXT" << ansi::ANSI_RESET << std::endl;
        std::cout << ansi::ANSI_RED << "PLEASE CHECK THAT THE FILE EXISTS WITHIN THE SAME DIRECTORY AS MAIN.EXE AND CHECK FILE PERMISSIONS" << ansi::ANSI_RESET << std::endl;
        menu_choices::getStringChoice("PRESS ENTER TO ABORT.");
        exit(0);
    }
}

void files::Files::parseLoveLetterFiles() {
    debug_console::DebugConsole::elements.push_back("Started parsing love letter files");
    std::ifstream attentionGrabbersFile("Love Letter\\attentionGrabbers.txt");
    if (attentionGrabbersFile.is_open()) {
        debug_console::DebugConsole::elements.push_back("File Love Letter\\attentionGrabbers.txt is good");
        while (attentionGrabbersFile.good()) {
            std::string line;
            std::getline(attentionGrabbersFile, line);
            files::Files::attentionGrabbers.push_back(line);
        }
    } else {
        std::cout << ansi::ANSI_RED << "FATAL ERROR. CANNOT FIND OR READ FILE NAMED LOVE LETTER\\ATTENTIONGRABBERS.TXT" << ansi::ANSI_RESET << std::endl;
        std::cout << ansi::ANSI_RED << "PLEASE CHECK THAT THE FILE EXISTS WITHIN THE SAME DIRECTORY AS MAIN.EXE AND CHECK FILE PERMISSIONS" << ansi::ANSI_RESET << std::endl;
        menu_choices::getStringChoice("PRESS ENTER TO ABORT.");
        exit(0);
    }
    std::ifstream complementsFile("Love Letter\\complements.txt");
    if (complementsFile.is_open()) {
        debug_console::DebugConsole::elements.push_back("File Love Letter\\complements.txt is good");
        while (complementsFile.good()) {
            std::string line;
            std::getline(complementsFile, line);
            files::Files::complements.push_back(line);
        }
    } else {
        std::cout << ansi::ANSI_RED << "FATAL ERROR. CANNOT FIND OR READ FILE NAMED LOVE LETTER\\COMPLEMENTS.TXT" << ansi::ANSI_RESET << std::endl;
        std::cout << ansi::ANSI_RED << "PLEASE CHECK THAT THE FILE EXISTS WITHIN THE SAME DIRECTORY AS MAIN.EXE AND CHECK FILE PERMISSIONS" << ansi::ANSI_RESET << std::endl;
        menu_choices::getStringChoice("PRESS ENTER TO ABORT.");
        exit(0);
    }
    std::ifstream theDetailsFile("Love Letter\\theDetails.txt");
    if (theDetailsFile.is_open()) {
        debug_console::DebugConsole::elements.push_back("File Love Letter\\theDetails.txt is good");
        while (theDetailsFile.good()) {
            std::string line;
            std::getline(theDetailsFile, line);
            files::Files::details.push_back(line);
        }
    } else {
        std::cout << ansi::ANSI_RED << "FATAL ERROR. CANNOT FIND OR READ FILE NAMED LOVE LETTER\\THEDETAILS.TXT" << ansi::ANSI_RESET << std::endl;
        std::cout << ansi::ANSI_RED << "PLEASE CHECK THAT THE FILE EXISTS WITHIN THE SAME DIRECTORY AS MAIN.EXE AND CHECK FILE PERMISSIONS" << ansi::ANSI_RESET << std::endl;
        menu_choices::getStringChoice("PRESS ENTER TO ABORT.");
        exit(0);
    }
}

void files::Files::parseInsults() {
    debug_console::DebugConsole::elements.push_back("Started parsing insult file");
    std::ifstream insults("insults.txt");
    if (insults.is_open()) {
        debug_console::DebugConsole::elements.push_back("File insults.txt is good");
        while (insults.good()) {
            std::string line;
            std::getline(insults, line);
            files::Files::insults.push_back(line);
        }
    } else {
        std::cout << ansi::ANSI_RED << "FATAL ERROR. CANNOT FIND OR READ FILE NAMED INSULTS.TXT" << ansi::ANSI_RESET << std::endl;
        std::cout << ansi::ANSI_RED << "PLEASE CHECK THAT THE FILE EXISTS WITHIN THE SAME DIRECTORY AS MAIN.EXE AND CHECK FILE PERMISSIONS" << ansi::ANSI_RESET << std::endl;
        menu_choices::getStringChoice("PRESS ENTER TO ABORT.");
        exit(0);
    }   
}