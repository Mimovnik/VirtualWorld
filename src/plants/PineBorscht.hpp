#ifndef PINEBORSCHT_HPP
#define PINEBORSCHT_HPP

#include "../Plant.hpp"

class PineBorscht : public Plant {
   public:
    PineBorscht(World* world)
        : Plant(world, PINEBORSCHT_STRENGTH, PINEBORSCHT_INITIATIVE,
                PINEBORSCHT_SKIN, "Pine Borscht") {}
};

#endif