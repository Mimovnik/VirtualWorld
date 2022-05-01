#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "../Animal.hpp"

class Human : public Animal {
    static int counter;

   public:
    Human(World* world)
        : Animal(world, HUMAN_STRENGTH, HUMAN_INITIATIVE, HUMAN_SKIN,
                 "Player") {
        counter++;
        name += "(" + std::to_string(counter) + ")";
    }

    int getDirection() override;


    Animal* giveBirth() override;
};

#endif