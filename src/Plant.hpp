#ifndef PLANT_HPP
#define PLANT_HPP

#include "Organism.hpp"

class Plant : public Organism {
   public:
    Plant();
    Plant(World* world, int strength, int initiative, char skin);
    void action() override{

    };
    void collide(std::unique_ptr<Organism>* other) override{

    };
};

#endif