#include "random.hpp"
#include "debugConsole.hpp"

#include <random>

int random::randomInRange(int min, int max) {
    debug_console::DebugConsole::elements.push_back("Random value generation begun with range" + std::to_string(min) + "-" + std::to_string(max));
    std::random_device random;
    std::mt19937 generate(random());
    std::uniform_int_distribution<int> distribution(min, max);
    debug_console::DebugConsole::elements.push_back("Random value successfully created");
    return distribution(generate);
}