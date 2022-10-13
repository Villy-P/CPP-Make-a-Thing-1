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
#include <tgmath.h>

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
    std::cout << "5  | VIEW DATA                             |" << std::endl;
    std::cout << "6  | EXIT                                  |" << std::endl;
    std::cout << "7  | MAKE MORE MONEY                       |" << std::endl;
    std::cout << "8  | GET WORDS                             |" << std::endl;
    std::cout << "9  | DEBUG CONSOLE (ONLY FOR DEVELOPER)    |" << std::endl;
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
            player.amountSpent += 5;
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
            player.amountSpent += 7;
            debug_console::DebugConsole::elements.push_back("Player cash reduced by 7");
            std::string item = files::Files::dreams[random::randomInRange(0, files::Files::dreams.size() - 1)];
            player.knownDreams.push_back(item);
            std::cout << ansi::ANSI_ORANGE << "\"" << item << "\"" << ansi::ANSI_RESET << std::endl;
            debug_console::DebugConsole::elements.push_back("Dream recited");
            files::Files::dreams.erase(std::remove(files::Files::dreams.begin(), files::Files::dreams.end(), item), files::Files::dreams.end());
            debug_console::DebugConsole::elements.push_back("Dream removed");
            menu_choices::getStringChoice("");
            std::cout << ansi::ANSI_CLEAR << std::endl;
            menu::wordsMenu(player);
            break;
        } case 3: {
            std::cout << ansi::ANSI_CLEAR << std::endl;
            if (files::Files::attentionGrabbers.size() == 0) {
                std::cout << ansi::ANSI_RED << "Belisa has run out of things to write." << ansi::ANSI_RESET << std::endl;
                menu_choices::getStringChoice("");
                std::cout << ansi::ANSI_CLEAR << std::endl;
                menu::wordsMenu(player);
                break;
            }
            if (player.cash < 9) {
                std::cout << ansi::ANSI_RED << "You can't afford that!" << ansi::ANSI_RESET << std::endl;
                menu_choices::getStringChoice("");
                std::cout << ansi::ANSI_CLEAR << std::endl;
                menu::wordsMenu(player);
                break;
            }
            player.cash -= 9;
            player.amountSpent += 9;
            debug_console::DebugConsole::elements.push_back("Player cash reduced by 9");
            std::string to = menu_choices::getStringChoice("\"Who am I writing this letter to?\"  >");
            std::string letter = "Dearest " + to + ",\n\t";
            std::string attentionGrabber = files::Files::attentionGrabbers[random::randomInRange(0, files::Files::attentionGrabbers.size() - 1)];
            letter += attentionGrabber += " ";
            files::Files::attentionGrabbers.erase(std::remove(files::Files::attentionGrabbers.begin(), files::Files::attentionGrabbers.end(), attentionGrabber), files::Files::attentionGrabbers.end());
            for (unsigned char i = 0; i < 10; i++) {
                std::string complement = files::Files::complements[random::randomInRange(0, files::Files::complements.size() - 1)];
                letter += complement + " ";
                files::Files::complements.erase(std::remove(files::Files::complements.begin(), files::Files::complements.end(), complement), files::Files::complements.end());
            }
            std::string detail = files::Files::details[random::randomInRange(0, files::Files::details.size() - 1)];
            letter += detail;
            files::Files::details.erase(std::remove(files::Files::details.begin(), files::Files::details.end(), detail), files::Files::details.end());
            letter += "\n\t\t\tSincerely, " + player.name;
            player.knownLoveLetters.push_back(letter);
            debug_console::DebugConsole::elements.push_back("Letter Constructed");
            std::cout << ansi::ANSI_MAGENTA << letter << ansi::ANSI_RESET << std::endl;
            debug_console::DebugConsole::elements.push_back("Letter Recited");
            menu_choices::getStringChoice("");
            std::cout << ansi::ANSI_CLEAR << std::endl;
            menu::wordsMenu(player);
            break;
        } case 4: {
            std::cout << ansi::ANSI_CLEAR << std::endl;
            if (files::Files::dreams.size() == 0) {
                std::cout << ansi::ANSI_RED << "Belisa has run out of things to say to you." << ansi::ANSI_RESET << std::endl;
                menu_choices::getStringChoice("");
                std::cout << ansi::ANSI_CLEAR << std::endl;
                menu::wordsMenu(player);
                break;
            }
            if (player.cash < 12) {
                std::cout << ansi::ANSI_RED << "You can't afford that!" << ansi::ANSI_RESET << std::endl;
                menu_choices::getStringChoice("");
                std::cout << ansi::ANSI_CLEAR << std::endl;
                menu::wordsMenu(player);
                break;
            }
            player.cash -= 12;
            player.amountSpent += 12;
            debug_console::DebugConsole::elements.push_back("Player cash reduced by 12");
            std::string item = files::Files::insults[random::randomInRange(0, files::Files::insults.size() - 1)];
            player.knownInsults.push_back(item);
            std::cout << ansi::ANSI_RED << "\"" << item << "\"" << ansi::ANSI_RESET << std::endl;
            debug_console::DebugConsole::elements.push_back("Dream recited");
            files::Files::insults.erase(std::remove(files::Files::insults.begin(), files::Files::insults.end(), item), files::Files::insults.end());
            debug_console::DebugConsole::elements.push_back("Dream removed");
            menu_choices::getStringChoice("");
            std::cout << ansi::ANSI_CLEAR << std::endl;
            menu::wordsMenu(player);
            break;
            break;
        } case 5:
            std::cout << ansi::ANSI_CLEAR << std::endl;
            std::cout << ansi::ANSI_BLUE << "Verses Known:\n" << ansi::ANSI_RESET << std::endl;
            for (std::string s : player.knownVerses)
                std::cout << ansi::ANSI_BLUE << s << "\n" << ansi::ANSI_RESET << std::endl;
            std::cout << ansi::ANSI_ORANGE << "Dream Quality Improvers Known:\n" << ansi::ANSI_RESET << std::endl;
            for (std::string s : player.knownDreams)
                std::cout << ansi::ANSI_ORANGE << s << "\n" << ansi::ANSI_RESET << std::endl;
            std::cout << ansi::ANSI_MAGENTA << "Love letters known:\n" << ansi::ANSI_RESET << std::endl;
            for (std::string s : player.knownLoveLetters)
                std::cout << ansi::ANSI_MAGENTA << s << "\n" << ansi::ANSI_RESET << std::endl;
            std::cout << ansi::ANSI_GREEN << "Insults known:\n" << ansi::ANSI_RESET << std::endl;
            for (std::string s : player.knownInsults) 
                std::cout << ansi::ANSI_GREEN << s << "\n" << ansi::ANSI_RESET << std::endl;
            menu_choices::getStringChoice("");
            std::cout << ansi::ANSI_CLEAR << std::endl;
            menu::wordsMenu(player);
            break;
        case 6:
            std::cout << ansi::ANSI_CLEAR << std::endl;
            std::cout << ansi::ANSI_RED << "Are you sure you want to exit?" << std::endl;
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
        case 7: {
            int amount = random::randomInRange(20, 100);
            std::cout << ansi::ANSI_ORANGE << "You made $" << amount << ansi::ANSI_RESET << std::endl;
            player.cash += amount;
            menu_choices::getStringChoice("");
            std::cout << ansi::ANSI_CLEAR << std::endl;
            menu::wordsMenu(player);
            break;
        } case 8: {
            if (player.amountSpent < 50) {
                std::cout << ansi::ANSI_RED << "You have not payed 50 centavos yet!" << ansi::ANSI_RESET << std::endl;
                menu_choices::getStringChoice("");
                std::cout << ansi::ANSI_CLEAR << std::endl;
                menu::wordsMenu(player);
                break;
            }
            std::cout << ansi::ANSI_RED << "The words Belisa gives you make you insane!" << ansi::ANSI_RESET << std::endl;
            menu_choices::getStringChoice("");
            exit(0);
            break;
        } case 9: {
            std::cout << ansi::ANSI_CLEAR << std::endl;
            for (std::string s : debug_console::DebugConsole::elements)
                std::cout << s << std::endl;
            menu_choices::getStringChoice("");
            std::cout << ansi::ANSI_CLEAR << std::endl;
            menu::wordsMenu(player);
            break;
        }
    }
}