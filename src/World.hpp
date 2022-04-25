#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>

#include "Organism.hpp"

class World {
   protected:
    int width, height;
    char* terrain = nullptr;
    std::vector<std::unique_ptr<Organism>> organisms;

    friend std::ostream& operator<<(std::ostream& os, const World& world);

    void sortOrganisms();

   public:
    World(int width, int heigth);

    char* getCell(int x, int y);

    char* getCell(Vector position);

    void draw();

    void renderOrganisms();

    void makeTurns();

    Vector getRandomEmptyPos();

    int getSize() const;

    int getWidth() const;

    int getHeight() const;
};

#endif