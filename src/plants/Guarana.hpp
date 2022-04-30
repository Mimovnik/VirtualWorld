#ifndef GUARANA_HPP
#define GUARANA_HPP

#include "../Plant.hpp"

class Guarana : public Plant {
   public:
    Guarana(World* world)
        : Plant(world, GUARANA_STRENGTH, GUARANA_INITIATIVE, GUARANA_SKIN, "Guarana") {}
};

#endif