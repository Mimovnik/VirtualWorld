#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include <string>

#include "Organism.hpp"

class World {
   protected:
    int width, height;
    char* terrain = nullptr;
    std::vector<Organism*> organisms;
    int turnCount;
    std::string combatLog;
    unsigned int turnWait;
    bool drawAfterAction;

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

    void addOrganism(Organism* newborn, Vector bornPos);

    void writeEvent(std::string event);

    int getSize() const;

    int getWidth() const;

    int getHeight() const;
    
    int getTurnCount() const;

    void addTurn();

    Vector getRandomEmptyPos();

    Organism* getOrganismByPos(Vector position);
    
    Organism* getColliderWith(Organism* attacker);
};

#endif