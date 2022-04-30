#ifndef ANTELOPE_HPP
#define ANTELOPE_HPP

#include "../Animal.hpp"

class Antelope : public Animal {
   public:
    Antelope(World* world)
        : Animal(world, ANTELOPE_STRENGTH, ANTELOPE_INITIATIVE, ANTELOPE_SKIN,
                 "Antelope") {
    }
};

#endif