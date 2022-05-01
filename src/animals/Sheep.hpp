#ifndef SHEEP_HPP
#define SHEEP_HPP

#include "../Animal.hpp"

class Sheep : public Animal {
    static int counter;

   public:
    Sheep(World* world)
        : Animal(world, SHEEP_STRENGTH, SHEEP_INITIATIVE, SHEEP_SKIN, "Sheep") {
        counter++;
        name += "(" + std::to_string(counter) + ")";
    }
};

#endif