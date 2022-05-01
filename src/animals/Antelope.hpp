#ifndef ANTELOPE_HPP
#define ANTELOPE_HPP

#include "../Animal.hpp"

class Antelope : public Animal {
    static int counter;

   public:
    Antelope(World* world)
        : Animal(world, ANTELOPE_STRENGTH, ANTELOPE_INITIATIVE, ANTELOPE_SKIN,
                 "Antelope") {
        counter++;
        name += "(" + std::to_string(counter) + ")";
    }
};

#endif