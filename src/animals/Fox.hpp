#ifndef FOX_HPP
#define FOX_HPP

#include "../Animal.hpp"

class Fox : public Animal {
   public:
    Fox() {
        this->strenght = FOX_STRENGTH;
        this->initiative = FOX_INITIATIVE;
        this->position = Vector::ZERO;
        this->skin = FOX_SKIN;
    }
};

#endif