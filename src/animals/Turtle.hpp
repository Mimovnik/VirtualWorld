#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "../Animal.hpp"

class Turtle : public Animal {
   public:
    Turtle(World* world)
        : Animal(world, TURTLE_STRENGTH, TURTLE_INITIATIVE, TURTLE_SKIN, "Turtle") {}
};

#endif