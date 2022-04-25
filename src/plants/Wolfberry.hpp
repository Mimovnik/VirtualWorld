#ifndef WOLFBERRY_HPP
#define WOLFBERRY_HPP

#include "../Plant.hpp"

class Wolfberry : public Plant {
   public:
    Wolfberry(World* world)
        : Plant(world, WOLF_STRENGTH, WOLF_INITIATIVE, WOLF_SKIN) {}
};

#endif