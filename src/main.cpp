#include <cstdlib>
#include <time.h>

#include <iostream>

#include "World.hpp"

#define ID_NAME "Jakub Kwidzinski 188647"
int game() {
    std::system("clear");
    srand(time(NULL));
    bool running = true;

    std::cout << ID_NAME << std::endl;
    std::cout << "Wpisz szerokosc, a nastepnie wysokosc planszy:";
    int width, height;
    std::cin >> width >> height;
    World world(width, height);
    int turnCount = 0;
    while (running) {
        turnCount++;
        std::system("clear");
        std::cout << "Tura: " << turnCount << std::endl;
        world.removeDeadOrganisms();
        world.makeTurns();
        world.draw();

        std::cout << "n- nastepna tura, x- wyjscie z gry\n";
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