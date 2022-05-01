#include "Animal.hpp"

#include <iostream>

#include "World.hpp"

Animal::Animal() {}

Animal::Animal(World* world, int strength, int initiative, char skin,
               std::string name)
    : Organism(world, strength, initiative, skin, name) {
    attackedThisTurn = false;
    moveRange = 1;
}

void Animal::move(int direction) {
    world->writeEvent(name);
    switch (direction) {
        case -1:
            world->writeEvent(" doesn't move.");
            break;
        case 0:
            if (position.x + 1 < world->getWidth()) {
                world->writeEvent(" moves right.");
                position.x += 1;
                break;
            }
            world->writeEvent(" tries to move right but hits a wall.");
            break;
        case 1:
            if (position.x > 0) {
                world->writeEvent(" moves left.");
                position.x -= 1;
                break;
            }
            world->writeEvent(" tries to move left but hits a wall.");
            break;
        case 2:
            if (position.y + 1 < world->getHeight()) {
                world->writeEvent(" moves down.");
                position.y += 1;
                break;
            }
            world->writeEvent(" tries to move down but hits a wall.");
            break;
        case 3:
            if (position.y > 0) {
                world->writeEvent(" moves up.");
                position.y -= 1;
                break;
            }
            world->writeEvent(" tries to move up but hits a wall.");
            break;
    }
    world->writeEvent("\n");
}

int Animal::getDirection() { return rand() % 4; }

void Animal::breed(Organism* partner) {
    moveBack();
    int nearX = rand() % 3 - 1;
    int nearY = rand() % 3 - 1;
    Vector birthPosition = getPos().addX(nearX).addY(nearY);
    if (birthPosition.x < 0 || birthPosition.x >= world->getWidth() ||
        birthPosition.y < 0 || birthPosition.y >= world->getHeight()) {
        return;
    }

    if (world->getOrganismByPos(birthPosition) == nullptr) {
        world->writeEvent(name + " have a baby with " + partner->getName() +
                          ".\n");

        world->addOrganism(giveBirth(), birthPosition);
    }
}

void Animal::action() {
    attackedThisTurn = false;
    if (stunned) {
        stunned = false;
        return;
    }
    int direction = getDirection();
    for (int i = 0; i < moveRange; i++) {
        if (dead) {
            break;
        }
        lastPosition = position;
        move(direction);
        // Organism beeing attacked by this Animal
        Organism* defender = world->getColliderWith(this);
        if (defender != nullptr) {
            // Organisms are of the same specie
            if (defender->getSkin() == skin) {
                breed(defender);
                return;
            }
            attackedThisTurn = true;
            world->writeEvent(name + " attacks " + defender->getName() + "\n");
            collide(defender);
        }
    }
};

// *this* is attacked by *attacker*
void Animal::takeHit(Organism* attacker) {
    world->writeEvent(name + " took a hit from " + attacker->getName() +
                      " and died" + "\n");
    die();
};