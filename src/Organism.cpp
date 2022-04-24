#include "Organism.hpp"

Vector Organism::getPos() { return position; }

std::ostream& operator<<(std::ostream& os, const Organism& organism) {
    std::cout << organism.skin;
    return os;
}