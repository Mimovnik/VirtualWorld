#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Organism.hpp"

class Animal : public Organism {
   public:
    Animal();
    void action() override{

    };
    void collide() override{

    };
};

#endif