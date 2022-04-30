#ifndef WOLFBERRY_HPP
#define WOLFBERRY_HPP

#include "../Plant.hpp"

class Wolfberry : public Plant {
   public:
    Wolfberry(World* world)
        : Plant(world, WOLFBERRY_STRENGTH, WOLFBERRY_INITIATIVE, WOLFBERRY_SKIN, "Wolfberry") {}
};

#endif