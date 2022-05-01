#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Organism.hpp"

class Animal : public Organism {
   protected:
    bool attackedThisTurn;

    int moveRange;

    void move(int direction);

    void takeHit(Organism* attacker) override;

    virtual int getDirection();

    void breed(Organism* partner);

    virtual Animal* giveBirth() = 0;

   public:
    void action() override;

    Animal();

    Animal(World* world, int strength, int initiative, char skin,
           std::string name);
};

#endif