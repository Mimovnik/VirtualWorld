#ifndef ORGANISM_HPP
#define ORGANISM_HPP

#include <time.h>

#include <iostream>

#include "Vector.hpp"
#include "settings.hpp"
class World;
class Organism {
   protected:
    int strength;
    int initiative;
    Vector position;
    char skin;
    int birthDate;
    World* world = nullptr;
    static int organismsCount;

    friend std::ostream& operator<<(std::ostream& os, const Organism& organism);

   public:
    Organism();

    Organism(World* world, int strength, int initiative, char skin);

    friend bool compareOrganisms(Organism* left, Organism* right);

    Vector getPos();

    char getSkin();

    int getBirthDate();

    bool isStronger(Organism* other);

    virtual void action() = 0;

    virtual void collide(Organism* defender) = 0;

    virtual void takeHit(Organism* attacker) = 0;
};

#endif