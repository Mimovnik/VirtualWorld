#include "Organism.hpp"

#include "World.hpp"

int Organism::organismsCount = 0;

Organism::Organism() {
    stunned = false;
    dead = false;
    position = Vector();
    lastPosition = position;
}

Organism::Organism(World* world, int strength, int initiative, char skin,
                   std::string name_) {
    organismsCount++;
    this->name = name_;
    this->stunned = false;
    this->dead = false;
    this->world = world;
    this->strength = strength;
    this->initiative = initiative;
    this->skin = skin;
    this->position = world->getRandomEmptyPos();
    this->lastPosition = position;
    this->birthDate = organismsCount;
}

Vector Organism::getPos() { return position; }

void Organism::setPos(Vector newPos) { this->position = newPos; }

std::string Organism::getName() { return name; }

std::ostream& operator<<(std::ostream& os, const Organism& organism) {
    std::cout << organism.skin;
    return os;
}

void Organism::stun() { stunned = true; }

void Organism::die() { dead = true; }

bool Organism::isDead() { return dead; }

// *this* is attacking *defender*
void Organism::collide(Organism* defender) {
    if (defender->isStronger(this)) {
        takeHit(defender);
    } else {
        defender->takeHit(this);
    }
};

bool Organism::isStronger(Organism* other) {
    return strength >= other->strength;
}

void Organism::moveBack() { position = lastPosition; }

char Organism::getSkin() { return skin; }

int Organism::getBirthDate() { return birthDate; }

int Organism::getStrength() { return strength; }