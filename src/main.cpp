#include <cstdlib>
#include <time.h>

#include <iostream>

#include "World.hpp"

#define ID_NAME "Jakub Kwidzinski 188647"
int game() {
    srand(time(NULL));
    bool running = true;

    std::cout << ID_NAME << std::endl;
    std::cout << "Type width and height of the board:";
    int width, height;
    std::cin >> width >> height;
    World world(width, height);
    while (running) {
        world.addTurn();
        world.draw();
        world.makeTurns();

        std::cout << "n- next turn, x- exit the game\n";
        char input;
        while (std::cin >> input) {
            if (input == 'n') {
                break;
            }
            if (input == 'x'){
                running = false;
                break;
            }
        }
    }
    return 0;
}

int main() {
    try {
        return game();
    } catch (char* errorMsg) {
        std::cerr << errorMsg;
        return 1;
    }
}