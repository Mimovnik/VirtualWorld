#ifndef PINEBORSCHT_HPP
#define PINEBORSCHT_HPP

#include "../Plant.hpp"

class PineBorscht : public Plant {
    static int counter;

   public:
    PineBorscht(World* world)
        : Plant(world, PINEBORSCHT_STRENGTH, PINEBORSCHT_INITIATIVE,
                PINEBORSCHT_SKIN, "Pine Borscht") {
        counter++;
        name += "(" + std::to_string(counter) + ")";
    }
};

#endif