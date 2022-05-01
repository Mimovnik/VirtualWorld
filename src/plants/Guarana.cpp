#include "Guarana.hpp"

#include "../World.hpp"

int Guarana::counter = 0;

Plant* Guarana::getSapling() { return new Guarana(world); }

void Guarana::takeHit(Organism* attacker) {
    world->writeEvent(name + " got eaten by " + attacker->getName() + "\n");
    die();
    attacker->buff(3);
}