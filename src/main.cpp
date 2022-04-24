#include <Windows.h>

#include <iostream>

#include "World.hpp"

#define ID_NAME "Jakub Kwidzinski 188647"

int main() {
    system("cls");

    bool running = true;

    std::cout << ID_NAME << std::endl;
    std::cout << "Wpisz szerokosc, a nastepnie wysokosc planszy:";
    int width, height;
    std::cin >> width >> height;

    World world(width, height);
    while (running) {
        std::cout << "n- nastepna tura\n";
        world.draw();

        char ready;
        while (std::cin >> ready) {
            if (ready == 'n') {
                break;
            }
        }
    }
}
