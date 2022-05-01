#ifndef DANDELION_HPP
#define DANDELION_HPP

#include "../Plant.hpp"

class Dandelion : public Plant {
    static int counter;

   public:
    Dandelion(World* world)
        : Plant(world, DANDELION_STRENGTH, DANDELION_INITIATIVE, DANDELION_SKIN,
                "Dandelion") {
        counter++;
        name += "(" + std::to_string(counter) + ")";

        spreadTries = 3;
    }
    
    Plant* getSapling() override;
};

#endif