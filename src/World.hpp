#ifndef WORLD_HPP
#define WORLD_HPP

#include "Organism.hpp"
#include <vector>

class World {
   protected:
    int width, height;
    char* terrain = nullptr;
    std::vector<std::unique_ptr<Organism>> organisms;

    friend std::ostream& operator<<(std::ostream& os, const World& world);

   public:
    World(int width, int heigth);

    char* getCell(int x, int y);

    char* getCell(Vector position);

    void draw();

    void renderOrganisms();
};

#endif