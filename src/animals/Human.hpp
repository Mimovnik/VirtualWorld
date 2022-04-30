#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "../Animal.hpp"

class Human : public Animal {
   public:
    Human(World* world)
        : Animal(world, HUMAN_STRENGTH, HUMAN_INITIATIVE, HUMAN_SKIN) {}

    void action() override;
};

#endif