#include "Organism.hpp"

Organism::Organism() {}

Vector Organism::getPos() { return position; }

std::ostream& operator<<(std::ostream& os, const Organism& organism) {
    std::cout << organism.skin;
    return os;
}

char Organism::getSkin() { return skin; }