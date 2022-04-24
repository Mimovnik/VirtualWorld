#ifndef GRASS_HPP
#define GRASS_HPP

#include "../Plant.hpp"

class Grass : public Plant {
   public:
    Grass() {
        this->strenght = GRASS_STRENGTH;
        this->initiative = GRASS_INITIATIVE;
        this->position = Vector::ZERO;
        this->skin = GRASS_SKIN;
    }
};

#endif