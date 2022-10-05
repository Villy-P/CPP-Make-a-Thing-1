#include "player.hpp"

#include <string>

player::Player::Player(std::string name, int cash) {
    this->name = name;
    this->cash = cash;
}