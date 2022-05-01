#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "../Animal.hpp"

class Turtle : public Animal {
    static int counter;

   public:
    Turtle(World* world)
        : Animal(world, TURTLE_STRENGTH, TURTLE_INITIATIVE, TURTLE_SKIN,
                 "Turtle") {
        counter++;
        name += "(" + std::to_string(counter) + ")";
    }

    int getDirection() override;

    void takeHit(Organism* attacker) override;
};

#endif