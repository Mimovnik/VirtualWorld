#ifndef PINEBORSCHT_HPP
#define PINEBORSCHT_HPP

#include "../Plant.hpp"

class PineBorscht : public Plant {
   public:
    PineBorscht() {
        this->strenght = PINEBORSCHT_STRENGTH;
        this->initiative = PINEBORSCHT_INITIATIVE;
        this->position = Vector::ZERO;
        this->skin = PINEBORSCHT_SKIN;
    }
};

#endif