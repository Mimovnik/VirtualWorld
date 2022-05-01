#ifndef GRASS_HPP
#define GRASS_HPP

#include "../Plant.hpp"

class Grass : public Plant {
    static int counter;

   public:
    Grass(World* world)
        : Plant(world, GRASS_STRENGTH, GRASS_INITIATIVE, GRASS_SKIN, "Grass") {
        counter++;
        name += "(" + std::to_string(counter) + ")";
    }
    
    Plant* getSapling() override;
};

#endif