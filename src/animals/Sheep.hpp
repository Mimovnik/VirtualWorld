#ifndef SHEEP_HPP
#define SHEEP_HPP

#include "../Animal.hpp"

class Sheep : public Animal {
   public:
    Sheep() {
        this->strenght = SHEEP_STRENGTH;
        this->initiative = SHEEP_INITIATIVE;
        this->position = Vector::ZERO;
        this->skin = SHEEP_SKIN;
    }
};

#endif