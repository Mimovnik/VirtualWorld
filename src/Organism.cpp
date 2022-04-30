#include "Organism.hpp"

#include "World.hpp"

int Organism::organismsCount = 0;

Organism::Organism() {
    dead = false;
    position = Vector();
}

Organism::Organism(World* world, int strength, int initiative, char skin,
                   std::string name_) {
    organismsCount++;
    this->name = name_;
    this->dead = false;
    this->world = world;
    this->strength = strength;
    this->initiative = initiative;
    this->skin = skin;
    this->position = world->getRandomEmptyPos();
    this->birthDate = organismsCount;
}

Vector Organism::getPos() { return position; }

std::string Organism::getName() { return name; }

std::ostream& operator<<(std::ostream& os, const Organism& organism) {
    std::cout << organism.skin;
    return os;
}
void Organism::die() { dead = true; }

bool Organism::isDead() { return dead; }

// *this* is attacking *defender*
void Organism::collide(Organism* defender) {
    if (isStronger(defender)) {
        defender->takeHit(this);
    } else {
        takeHit(defender);
    }
};

bool Organism::isStronger(Organism* other) {
    return strength >= other->strength;
}

char Organism::getSkin() { return skin; }

int Organism::getBirthDate() { return birthDate; }