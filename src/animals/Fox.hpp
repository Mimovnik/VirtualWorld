#ifndef FOX_HPP
#define FOX_HPP

#include "../Animal.hpp"

class Fox : public Animal {
    static int counter;

   public:
    Fox(World* world)
        : Animal(world, FOX_STRENGTH, FOX_INITIATIVE, FOX_SKIN, "Fox") {
        counter++;
        name += "(" + std::to_string(counter) + ")";
    }

    int getDirection() override;
};

#endif