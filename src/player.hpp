#ifndef SRC_PLAYER_HPP
#define SRC_PLAYER_HPP

#include <string>
#include <vector>

#include "random.cpp"

namespace player {
    class Player {
        public:
            std::string name;
            int cash;
            std::vector<std::string> knownVerses;
            std::vector<std::string> knownDreams;
            std::vector<std::string> knownLoveLetters;

            Player(std::string name, int cash);
    };
}

#endif