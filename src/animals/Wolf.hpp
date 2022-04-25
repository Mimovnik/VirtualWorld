#ifndef WOLF_HPP
#define WOLF_HPP

#include "../Animal.hpp"

class Wolf : public Animal {
   public:
    Wolf(World* world)
        : Animal(world, WOLF_STRENGTH, WOLF_INITIATIVE, WOLF_SKIN) {}
};

#endif