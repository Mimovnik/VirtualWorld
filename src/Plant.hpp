#ifndef PLANT_HPP
#define PLANT_HPP

#include "Organism.hpp"

class Plant : public Organism {
   protected:
    void takeHit(Organism* attacker) override;

   public:
    Plant();

    Plant(World* world, int strength, int initiative, char skin, std::string name);

    void action() override;
};

#endif