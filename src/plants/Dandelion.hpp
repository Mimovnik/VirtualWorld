#ifndef DANDELION_HPP
#define DANDELION_HPP

#include "../Plant.hpp"

class Dandelion : public Plant {
   public:
    Dandelion() {
        this->strenght = DANDELION_STRENGTH;
        this->initiative = DANDELION_INITIATIVE;
        this->position = Vector::ZERO;
        this->skin = DANDELION_SKIN;
    }
};

#endif