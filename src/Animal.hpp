#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Organism.hpp"

class Animal : public Organism {
   protected:
    void move(int direction);

    void takeHit(Organism* attacker) override;

   public:
    void action() override;

    Animal();
    
    Animal(World* world, int strength, int initiative, char skin);
};

#endif