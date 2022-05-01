#include "Plant.hpp"

#include "World.hpp"

Plant::Plant() {}

Plant::Plant(World* world, int strength, int initiative, char skin,
             std::string name)
    : Organism(world, strength, initiative, skin, name) {
    spreadTries = 1;
}

void Plant::spread() {
    int nearX = rand() % 3 - 1;
    int nearY = rand() % 3 - 1;
    Vector sowPosition = getPos().addX(nearX).addY(nearY);
    if (sowPosition.x < 0 || sowPosition.x >= world->getWidth() ||
        sowPosition.y < 0 || sowPosition.y >= world->getHeight()) {
        return;
    }

    if (world->getOrganismByPos(sowPosition) == nullptr) {
        world->writeEvent(name + " is spreading.\n");

        world->addOrganism(getSapling(), sowPosition);
    }
}

void Plant::action() {
    if(stunned){
        stunned = false;
        return;
    }
    for (int i = 0; i < spreadTries; i++) {
        if (rand() % 2) {
            spread();
        }
    }
}

void Plant::takeHit(Organism* attacker) {
    world->writeEvent(name + " got eaten by " + attacker->getName() + "\n");
    die();
}