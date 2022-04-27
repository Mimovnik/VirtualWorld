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

    char* getCell(int x, int y);

    char* getCell(Vector position);

    void renderOrganisms();


   public:
    World(int width, int heigth);

    void makeTurns();

    void draw();

    void removeDeadOrganisms();

    int getSize() const;

    int getWidth() const;

    int getHeight() const;

    Vector getRandomEmptyPos();
    
    Organism* getColliderWith(Organism* attacker);
};

#endif