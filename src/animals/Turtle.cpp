#include "Turtle.hpp"

#include "../World.hpp"

int Turtle::counter = 0;

Animal* Turtle::giveBirth() { return new Turtle(world); }

int Turtle::getDirection() {
    if (rand() % 4 == 0) {
        return rand() % 4;
    }
    return -1;
}

void Turtle::takeHit(Organism* attacker) {
    // Attacker's strength is >= 5 and turtle didn't attack
    if (attacker->getStrength() < 5 && !attackedThisTurn) {
        world->writeEvent(name + " resisted a hit from " + attacker->getName() +
                          "\n");
        attacker->moveBack();
    } else {
        world->writeEvent(name + " took a hit from " + attacker->getName() +
                          " and died" + "\n");

        die();
    }
}