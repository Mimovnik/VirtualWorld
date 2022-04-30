#ifndef SHEEP_HPP
#define SHEEP_HPP

#include "../Animal.hpp"

class Sheep : public Animal {
   public:
    Sheep(World* world)
        : Animal(world, SHEEP_STRENGTH, SHEEP_INITIATIVE, SHEEP_SKIN, "Sheep") {}
};

#endif