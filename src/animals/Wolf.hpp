#ifndef WOLF_HPP
#define WOLF_HPP

#include "../Animal.hpp"

class Wolf : public Animal {
   public:
    Wolf() {
        this->strenght = WOLF_STRENGTH;
        this->initiative = WOLF_INITIATIVE;
        this->position = Vector::ZERO;
        this->skin = WOLF_SKIN;
    }
};

#endif