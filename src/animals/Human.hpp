#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "../Animal.hpp"

class Human : public Animal {
   public:
    Human() {
        this->strenght = HUMAN_STRENGTH;
        this->initiative = HUMAN_INITIATIVE;
        this->position = Vector::ZERO;
        this->skin = HUMAN_SKIN;
    }
};

#endif