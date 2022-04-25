#ifndef FOX_HPP
#define FOX_HPP

#include "../Animal.hpp"

class Fox : public Animal {
   public:
    Fox(World* world)
        : Animal(world, FOX_STRENGTH, FOX_INITIATIVE, FOX_SKIN) {}
};

#endif