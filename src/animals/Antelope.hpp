#ifndef ANTELOPE_HPP
#define ANTELOPE_HPP

#include "../Animal.hpp"

class Antelope : public Animal {
   public:
    Antelope() {
        this->strenght = ANTELOPE_STRENGTH;
        this->initiative = ANTELOPE_INITIATIVE;
        this->position = Vector::ZERO;
        this->skin = ANTELOPE_SKIN;
    }
};

#endif