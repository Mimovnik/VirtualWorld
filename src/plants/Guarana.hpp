#ifndef GUARANA_HPP
#define GUARANA_HPP

#include "../Plant.hpp"

class Guarana : public Plant {
   public:
    Guarana() {
        this->strenght = GUARANA_STRENGTH;
        this->initiative = GUARANA_INITIATIVE;
        this->position = Vector::ZERO;
        this->skin = GUARANA_SKIN;
    }
};

#endif