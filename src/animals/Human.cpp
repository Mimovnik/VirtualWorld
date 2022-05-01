#include "Human.hpp"

#include "../World.hpp"

int Human::counter = 0;

Animal* Human::giveBirth() { return new Human(world); }

int Human::getDirection() {
    char input;
    int direction;
    while (true) {
        std::cout << "You're a human [H].\n w- move up, s- move down, a- move "
                     "left, d- move right";
        if (abilityActive) {
            std::cout << ", ability is active for next " << 5 - abilityTurns
                      << " turns.\n";
        } else if (abilityCooldown) {
            std::cout << ", ability is on cooldown for next " << abilityTurns
                      << " turns.\n";
        } else {
            std::cout << ", e- activate special ability\n";
        }
        std::cout << std::endl;
        std::cin >> input;
        if (input == 'd') {
            direction = 0;
            break;
        } else if (input == 'a') {
            direction = 1;
            break;
        } else if (input == 's') {
            direction = 2;
            break;
        } else if (input == 'w') {
            direction = 3;
            break;
        } else if (input == 'e' && !abilityActive && !abilityCooldown) {
            abilityActive = true;
        } else {
            std::cout << "There is no such command" << std::endl;
        }
    }
    return direction;
}

void Human::action() {
    attackedThisTurn = false;
    if (stunned) {
        stunned = false;
        return;
    }

    // Antelope's speed
    moveRange = 1;
    int direction = getDirection();
    if (abilityActive) {
        abilityTurns++;
        if (abilityTurns <= 3) {
            moveRange = 2;
        } else {
            if (rand() % 2) {
                world->writeEvent("lucky\n");
                moveRange = 2;
            }
        }
        if (abilityTurns >= 5) {
            abilityActive = false;
            abilityCooldown = true;
        }
    } else {
        abilityTurns--;
        if (abilityTurns <= 0) {
            abilityCooldown = false;
        }
    }

    for (int i = 0; i < moveRange; i++) {
        if(dead){
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