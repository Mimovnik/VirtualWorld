#include "Organism.hpp"

#include "World.hpp"

int Organism::organismsCount = 0;

Organism::Organism() { position = Vector(); }

Organism::Organism(World* world, int strength, int initiative, char skin) {
    organismsCount++;
    this->world = world;
    this->strength = strength;
    this->initiative = initiative;
    this->skin = skin;
    this->position = world->getRandomEmptyPos();
    this->birthDate = organismsCount;
}

Vector Organism::getPos() { return position; }

bool operator<(const Organism& left, const Organism& other) {
    return left.initiative < other.initiative;
}

std::ostream& operator<<(std::ostream& os, const Organism& organism) {
    std::cout << organism.skin;
    return os;
}

char Organism::getSkin() { return skin; }

int Organism::getBirthDate() { return birthDate; }