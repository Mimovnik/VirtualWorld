#ifndef WOLF_HPP
#define WOLF_HPP

#include "../Animal.hpp"

class Wolf : public Animal {
    static int counter;

   public:
    Wolf(World* world)
        : Animal(world, WOLF_STRENGTH, WOLF_INITIATIVE, WOLF_SKIN, "Wolf") {
        counter++;
        name += "(" + std::to_string(counter) + ")";
    }
};

#endif