#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "../Animal.hpp"

class Turtle : public Animal {
   public:
    Turtle() {
        this->strenght = TURTLE_STRENGTH;
        this->initiative = TURTLE_INITIATIVE;
        this->position = Vector::ZERO;
        this->skin = TURTLE_SKIN;
    }
};

#endif