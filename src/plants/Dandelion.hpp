#ifndef DANDELION_HPP
#define DANDELION_HPP

#include "../Plant.hpp"

class Dandelion : public Plant {
   public:
    Dandelion(World* world)
        : Plant(world, DANDELION_STRENGTH, DANDELION_INITIATIVE, DANDELION_SKIN) {}
};

#endif