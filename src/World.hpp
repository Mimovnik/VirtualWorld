#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>

#include "Organism.hpp"

class World {
   protected:
    int width, height;
    char* terrain = nullptr;
    std::vector<Organism*> organisms;

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

    Organism* getColliderWith(Organism* attacker);

    int getSize() const;

    int getWidth() const;

    int getHeight() const;
};

#endif