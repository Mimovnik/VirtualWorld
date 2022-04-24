#ifndef WORLD_HPP
#define WORLD_HPP

#include "Organism.hpp"

class World {
   protected:
    int width, height;
    Organism* terrain = nullptr;

    friend std::ostream& operator<<(std::ostream& os, const World& world);

   public:
    World(int width, int heigth);

    Organism getCell(int x, int y);

    Organism getCell(Vector position);

    void draw();
};

#endif