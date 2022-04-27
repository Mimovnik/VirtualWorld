#include "Plant.hpp"

Plant::Plant() {}

Plant::Plant(World* world, int strength, int initiative, char skin)
    : Organism(world, strength, initiative, skin) {}

void Plant::action() {
    
}

void Plant::takeHit(Organism* attacker) { die(); }