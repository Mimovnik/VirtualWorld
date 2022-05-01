#ifndef WOLFBERRY_HPP
#define WOLFBERRY_HPP

#include "../Plant.hpp"

class Wolfberry : public Plant {
    static int counter;

   public:
    Wolfberry(World* world)
        : Plant(world, WOLFBERRY_STRENGTH, WOLFBERRY_INITIATIVE, WOLFBERRY_SKIN,
                "Wolfberry") {
        counter++;
        name += "(" + std::to_string(counter) + ")";
    }
    
    bool isStronger(Organism* other) override;

    Plant* getSapling() override;
};

#endif