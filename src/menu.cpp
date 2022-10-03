#include "menu.hpp"
#include "getMenuChoice.cpp"
#include "ansi.hpp"
#include "files.hpp"
#include "random.hpp"

#include <iostream>
#include <string>
#include <limits>

void menu::wordsMenu() {
    debug_console::DebugConsole::elements.push_back("Begin printing menu");
    std::cout << ansi::ANSI_MAGENTA << "  +---------------------------------------+" << std::endl;
    std::cout << "  |                 WORDS                 |" << std::endl;
    std::cout << "  |                                       |" << std::endl;
    std::cout << "1 | VERSES FROM MEMORY         5 CENTAVOS |" << std::endl;
    std::cout << "2 | IMPROVE DREAM QUALITY      7 CENTAVOS |" << std::endl;
    std::cout << "3 | WRITE LOVE LETTER          9 CENTAVOS |" << std::endl;
    std::cout << "4 | MAKE UP INSULTS           12 CENTAVOS |" << std::endl;
    std::cout << "5 | WRITE A SPEECH                 1 PESO |" << std::endl;
    std::cout << "6 | VIEW DATA                             |" << std::endl;
    std::cout << "6 | SAVE DATA                             |" << std::endl;
    std::cout << "7 | LOAD DATA                             |" << std::endl;
    std::cout << "8 | EXIT                                  |" << std::endl;
    std::cout << "9 | DEBUG CONSOLE (ONLY FOR DEVELOPER)    |" << std::endl;
    std::cout << "  |                                       |" << std::endl;
    std::cout << "  |    ANYONE WHO PAYS 50 CENTAVOS WILL   |" << std::endl;
    std::cout << "  |  GET A WORD TO DRIVE AWAY MELENCHOLY  |" << std::endl;
    std::cout << "  +---------------------------------------+" << ansi::ANSI_RESET << std::endl;
    std::cout << ansi::ANSI_RED << "Enter the corresponding number to go to a specific menu." << ansi::ANSI_RESET << std::endl;
    debug_console::DebugConsole::elements.push_back("Stop printing menu");
    switch (menu_choices::getMenuChoice(">", 9)) {
        case 1:
            std::cout << ansi::ANSI_CLEAR << std::endl;
            std::cout << ansi::ANSI_BLUE << "\"" << files::Files::verses[random::randomInRange(0, files::Files::verses.size() - 1)] << "\"" << ansi::ANSI_RESET << std::endl;
            debug_console::DebugConsole::elements.push_back("Verse recited");
            menu_choices::getStringChoice("");
            std::cout << ansi::ANSI_CLEAR << std::endl;
            menu::wordsMenu();
            break;
        case 8:
            std::cout << ansi::ANSI_CLEAR << std::endl;
            std::cout << ansi::ANSI_RED << "Are you sure you want to exit? ANY UNSAVED DATA WILL BE LOST" << std::endl;
            std::cout << "Press ENTER TO EXIT and any DIGIT to go back." << ansi::ANSI_RESET << std::endl;
            switch (menu_choices::getMenuChoice(">", std::numeric_limits<int>::max())) {
                case 0:
                    exit(0);
                    break;
                case 1:
                    std::cout << ansi::ANSI_CLEAR << std::endl;
                    menu::wordsMenu();
                    break;
            }
            break;
        case 9:
            std::cout << ansi::ANSI_CLEAR << std::endl;
            for (std::string s : debug_console::DebugConsole::elements)
                std::cout << s << std::endl;
            menu_choices::getStringChoice("");
            std::cout << ansi::ANSI_CLEAR << std::endl;
            menu::wordsMenu();
            break;
    }
}