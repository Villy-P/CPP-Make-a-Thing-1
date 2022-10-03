#ifndef SRC_GETMENUCHOICE_HPP
#define SRC_GETMENUCHOICE_HPP

#include <string>

namespace menu_choices {
    unsigned char getMenuChoice(std::string prompt, int maxValue);
    std::string getStringChoice(std::string prompt);
}

#endif