#ifndef ORGANISM_HPP
#define ORGANISM_HPP

#include <time.h>
#include <string>
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
    std::string name;
    World* world = nullptr;
    bool dead;
    static int organismsCount;

    friend std::ostream& operator<<(std::ostream& os, const Organism& organism);

    void collide(Organism* defender);


    virtual void takeHit(Organism* attacker) = 0;

   public:
    Organism();

    Organism(World* world, int strength, int initiative, char skin, std::string name);

    virtual void action() = 0;

    friend bool compareOrganisms(Organism* left, Organism* right);

    bool isStronger(Organism* other);
    
    Vector getPos();

    char getSkin();

    std::string getName();

    int getBirthDate();

    void die();

    bool isDead();
};

#endif