#include "Animal.hpp"

Animal::Animal() {}

Animal::Animal(World* world, int strength, int initiative, char skin)
    : Organism(world, strength, initiative, skin) {}
