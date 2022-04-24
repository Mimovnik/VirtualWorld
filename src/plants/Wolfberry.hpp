#ifndef WOLFBERRY_HPP
#define WOLFBERRY_HPP

#include "../Plant.hpp"

class Wolfberry : public Plant {
   public:
    Wolfberry() {
        this->strenght = WOLFBERRY_STRENGTH;
        this->initiative = WOLFBERRY_INITIATIVE;
        this->position = Vector::ZERO;
        this->skin = WOLFBERRY_SKIN;
    }
};

#endif