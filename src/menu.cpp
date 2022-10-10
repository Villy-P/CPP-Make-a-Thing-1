#include "menu.hpp"
#include "getMenuChoice.cpp"
#include "ansi.hpp"
#include "files.hpp"
#include "random.hpp"
#include "player.hpp"

#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

void menu::wordsMenu(player::Player& player) {
    debug_console::DebugConsole::elements.push_back("Begin printing menu");
    std::cout << ansi::ANSI_GREEN << "You have " << std::to_string(player.cash) << " centavos. (100 centavos = 1 Peso)" << ansi::ANSI_RESET << std::endl;
    std::cout << ansi::ANSI_MAGENTA << "   +---------------------------------------+" << std::endl;
    std::cout << "   |                 WORDS                 |" << std::endl;
    std::cout << "   |                                       |" << std::endl;
    std::cout << "1  | VERSES FROM MEMORY         5 CENTAVOS |" << std::endl;
    std::cout << "2  | IMPROVE DREAM QUALITY      7 CENTAVOS |" << std::endl;
    std::cout << "3  | WRITE LOVE LETTER          9 CENTAVOS |" << std::endl;
    std::cout << "4  | MAKE UP INSULTS           12 CENTAVOS |" << std::endl;
    std::cout << "5  | WRITE A SPEECH                 1 PESO |" << std::endl;
    std::cout << "6  | VIEW DATA                             |" << std::endl;
    std::cout << "7  | SAVE DATA                             |" << std::endl;
    std::cout << "8  | LOAD DATA                             |" << std::endl;
    std::cout << "9  | EXIT                                  |" << std::endl;
    std::cout << "10 | MAKE MORE MONEY                       |" << std::endl;
    std::cout << "11 | DEBUG CONSOLE (ONLY FOR DEVELOPER)    |" << std::endl;
    std::cout << "   |                                       |" << std::endl;
    std::cout << "   |    ANYONE WHO PAYS 50 CENTAVOS WILL   |" << std::endl;
    std::cout << "   |  GET A WORD TO DRIVE AWAY MELENCHOLY  |" << std::endl;
    std::cout << "   +---------------------------------------+" << ansi::ANSI_RESET << std::endl;
    std::cout << ansi::ANSI_RED << "Enter the corresponding number to go to a specific menu." << ansi::ANSI_RESET << std::endl;
    debug_console::DebugConsole::elements.push_back("Stop printing menu");
    switch (menu_choices::getMenuChoice(">", 9)) {
        case 1: {
            std::cout << ansi::ANSI_CLEAR << std::endl;
            if (files::Files::verses.size() == 0) {
                std::cout << ansi::ANSI_RED << "Belisa has run out of verses to give you." << ansi::ANSI_RESET << std::endl;
                menu_choices::getStringChoice("");
                std::cout << ansi::ANSI_CLEAR << std::endl;
                menu::wordsMenu(player);
                break;
            }
            if (player.cash < 5) {
                std::cout << ansi::ANSI_RED << "You can't afford that!" << ansi::ANSI_RESET << std::endl;
                menu_choices::getStringChoice("");
                std::cout << ansi::ANSI_CLEAR << std::endl;
                menu::wordsMenu(player);
                break;
            }
            player.cash -= 5;
            debug_console::DebugConsole::elements.push_back("Player cash reduced by 5");
            std::string verse = files::Files::verses[random::randomInRange(0, files::Files::verses.size() - 1)];
            player.knownVerses.push_back(verse);
            std::cout << ansi::ANSI_BLUE << "\"" << verse << "\"" << ansi::ANSI_RESET << std::endl;
            debug_console::DebugConsole::elements.push_back("Verse recited");
            files::Files::verses.erase(std::remove(files::Files::verses.begin(), files::Files::verses.end(), verse), files::Files::verses.end());
            debug_console::DebugConsole::elements.push_back("Verse removed");
            menu_choices::getStringChoice("");
            std::cout << ansi::ANSI_CLEAR << std::endl;
            menu::wordsMenu(player);
            break;
        } case 2: {
            std::cout << ansi::ANSI_CLEAR << std::endl;
            if (files::Files::dreams.size() == 0) {
                std::cout << ansi::ANSI_RED << "Belisa has run out of things to say to you." << ansi::ANSI_RESET << std::endl;
                menu_choices::getStringChoice("");
                std::cout << ansi::ANSI_CLEAR << std::endl;
                menu::wordsMenu(player);
                break;
            }
            if (player.cash < 7) {
                std::cout << ansi::ANSI_RED << "You can't afford that!" << ansi::ANSI_RESET << std::endl;
                menu_choices::getStringChoice("");
                std::cout << ansi::ANSI_CLEAR << std::endl;
                menu::wordsMenu(player);
                break;
            }
            player.cash -= 7;
            debug_console::DebugConsole::elements.push_back("Player cash reduced by 7");
            std::string item = files::Files::dreams[random::randomInRange(0, files::Files::dreams.size() - 1)];
            player.knownDreams.push_back(item);
            std::cout << ansi::ANSI_BLUE << "\"" << item << "\"" << ansi::ANSI_RESET << std::endl;
            debug_console::DebugConsole::elements.push_back("Dream recited");
            files::Files::dreams.erase(std::remove(files::Files::dreams.begin(), files::Files::dreams.end(), item), files::Files::dreams.end());
            debug_console::DebugConsole::elements.push_back("Dream removed");
            menu_choices::getStringChoice("");
            std::cout << ansi::ANSI_CLEAR << std::endl;
            menu::wordsMenu(player);
            break;
        } case 6:
            std::cout << ansi::ANSI_CLEAR << std::endl;
            std::cout << ansi::ANSI_BLUE << "Verses Known:\n" << ansi::ANSI_RESET << std::endl;
            for (std::string s : player.knownVerses)
                std::cout << ansi::ANSI_BLUE << s << "\n" << ansi::ANSI_RESET << std::endl;
            std::cout << ansi::ANSI_BLUE << "Dream Quality Improvers Known:\n" << ansi::ANSI_RESET << std::endl;
            for (std::string s : player.knownDreams)
                std::cout << ansi::ANSI_ORANGE << s << "\n" << ansi::ANSI_RESET << std::endl;
            menu_choices::getStringChoice("");
            std::cout << ansi::ANSI_CLEAR << std::endl;
            menu::wordsMenu(player);
            break;
        case 9:
            std::cout << ansi::ANSI_CLEAR << std::endl;
            std::cout << ansi::ANSI_RED << "Are you sure you want to exit? ANY UNSAVED DATA WILL BE LOST" << std::endl;
            std::cout << "Press ENTER TO EXIT and any DIGIT to go back." << ansi::ANSI_RESET << std::endl;
            switch (menu_choices::getMenuChoice(">", std::numeric_limits<int>::max())) {
                case 0:
                    exit(0);
                    break;
                default:
                    std::cout << ansi::ANSI_CLEAR << std::endl;
                    menu::wordsMenu(player);
                    break;
            }
            break;
        case 11:
            std::cout << ansi::ANSI_CLEAR << std::endl;
            for (std::string s : debug_console::DebugConsole::elements)
                std::cout << s << std::endl;
            menu_choices::getStringChoice("");
            std::cout << ansi::ANSI_CLEAR << std::endl;
            menu::wordsMenu(player);
            break;
    }
}