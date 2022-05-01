#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "../Animal.hpp"

class Human : public Animal {
    static int counter;

    int abilityTurns;
    bool abilityActive;
    bool abilityCooldown;

   public:
    Human(World* world)
        : Animal(world, HUMAN_STRENGTH, HUMAN_INITIATIVE, HUMAN_SKIN,
                 "Player") {
        counter++;
        name += "(" + std::to_string(counter) + ")";

        abilityActive = false;
        abilityCooldown = false;
        abilityTurns = 0;
    }

    void action() override;

    int getDirection() override;

    Animal* giveBirth() override;
};

#endif