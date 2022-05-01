#ifndef GUARANA_HPP
#define GUARANA_HPP

#include "../Plant.hpp"

class Guarana : public Plant {
    static int counter;

   public:
    Guarana(World* world)
        : Plant(world, GUARANA_STRENGTH, GUARANA_INITIATIVE, GUARANA_SKIN,
                "Guarana") {
        counter++;
        name += "(" + std::to_string(counter) + ")";
    }
};

#endif