#include "Human.hpp"

#include "../World.hpp"

void Human::action() {
    char direction;
    while (true) {
        std::cout << "You're a human [H]. Type w s a d and hit enter to move" << std::endl;
        std::cin >> direction;
        if (direction == 'd') {
            move(0);
            break;
        } else if (direction == 'a') {
            move(1);
            break;
        } else if (direction == 's') {
            move(2);
            break;
        } else if (direction == 'w') {
            move(3);
            break;
        }else{
            std::cout << "There is no such direction" << std::endl;
        }
    }

    // Organism beeing attacked by this Animal
    Organism* defender = world->getColliderWith(this);
    if (defender != nullptr) {
        collide(defender);
    }
}