#include "menu.cpp"
#include "debugConsole.hpp"
#include "player.hpp"
#include "files.cpp"

int main(int argc, char const *argv[]) {
    files::Files::parseVersesTXT();
    debug_console::DebugConsole::elements.push_back("Program Started");
    menu::wordsMenu();
    debug_console::DebugConsole::elements.push_back("Program Ended");
    return 0;
}