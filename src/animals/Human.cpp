#include "Human.hpp"

#include "../World.hpp"

int Human::getDirection() {
    char input;
    int direction;
    while (true) {
        std::cout << "You're a human [H]. Type w s a d and hit enter to move"
                  << std::endl;
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
        } else {
            std::cout << "There is no such direction" << std::endl;
        }
    }
    return direction;
}