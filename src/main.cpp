#include "menu.cpp"
#include "debugConsole.hpp"
#include "player.hpp"
#include "files.cpp"
#include "player.cpp"

#include <string>
#include <limits>

int main(int argc, char const *argv[]) {
    files::Files::parseVersesTXT();
    files::Files::parseBetterDreams();
    files::Files::parseLoveLetterFiles();
    files::Files::parseInsults();
    files::Files::parseWords();
    debug_console::DebugConsole::elements.push_back("Program Started");
    std::string playerName = menu_choices::getStringChoice("Enter your name>");
    debug_console::DebugConsole::elements.push_back("Got name");
    int playerCash = menu_choices::getMenuChoice("How many centavos did you bring with you? (100 Centavos = 1 Peso)>", std::numeric_limits<int>::max());
    debug_console::DebugConsole::elements.push_back("Got centavos amount");
    player::Player player(playerName, playerCash);
    menu::wordsMenu(player);
    debug_console::DebugConsole::elements.push_back("Program Ended");
    return 0;
}