#ifndef ORGANISM_HPP
#define ORGANISM_HPP

#include <iostream>

#include "Vector.hpp"
#include "settings.hpp"

class Organism {
   protected:
    int strenght;
    int initiative;
    Vector position;
    char skin;

    friend std::ostream& operator<<(std::ostream& os, const Organism& organism);

   public:
    Organism();
    Vector getPos();
    virtual void action() = 0;
    virtual void collide() = 0;
    char getSkin();
};

#endif