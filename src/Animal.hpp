#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Organism.hpp"

class Animal : public Organism {
   protected:
    void move(int direction);

   public:
    Animal();
    Animal(World* world, int strength, int initiative, char skin);
    void action() override;
    void collide(Organism* defender) override;
    void takeHit(Organism* attacker) override;
};

#endif