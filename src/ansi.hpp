#ifndef SRC_ANSI_HPP
#define SRC_ANSI_HPP

#include <string>

namespace ansi {
    std::string ANSI_CLEAR     = "\033[2J";
    std::string ANSI_RESET     = "\033[0m";
    std::string ANSI_RED       = "\033[31m";
    std::string ANSI_GREEN     = "\033[32m";
    std::string ANSI_YELLOW    = "\033[33m";
    std::string ANSI_BLUE      = "\033[34m";
    std::string ANSI_MAGENTA   = "\033[35m";
    std::string ANSI_CYAN      = "\033[36m";
    std::string ANSI_WHITE     = "\033[37m";
    std::string ANSI_BROWN     = "\033[38;5;52m";
    std::string ANSI_DARK_CYAN = "\033[38;5;23m";
    std::string ANSI_ORANGE    = "\033[38;5;202m";
    std::string ANSI_PURPLE    = "\033[38;5;127m";
}

#endif