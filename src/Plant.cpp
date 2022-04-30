#include "Plant.hpp"
#include "World.hpp"

Plant::Plant() {}

Plant::Plant(World* world, int strength, int initiative, char skin,
             std::string name)
    : Organism(world, strength, initiative, skin, name) {}

void Plant::action() {}

void Plant::takeHit(Organism* attacker) {
    world->writeEvent(name + " got eaten by " + attacker->getName() + "\n");
    die();
}