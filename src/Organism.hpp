#ifndef ORGANISM_HPP
#define ORGANISM_HPP

#include <iostream>

#include "Vector.hpp"
#include "World.hpp"

class Organism {
   protected:
    int strenght;
    int initiative;
    Vector position;
    char skin;

    friend std::ostream& operator<<(std::ostream& os, const Organism& organism);

   public:
    Organism() {}
    Vector getPos();
    virtual void action();
    virtual void collide();
    virtual void render(World world);
};

#endif