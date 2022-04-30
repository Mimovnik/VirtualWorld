#ifndef GRASS_HPP
#define GRASS_HPP

#include "../Plant.hpp"

class Grass : public Plant {
   public:
    Grass(World* world)
        : Plant(world, GRASS_STRENGTH, GRASS_INITIATIVE, GRASS_SKIN, "Grass") {}
};

#endif