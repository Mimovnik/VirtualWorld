#include <iostream>
#include <Windows.h>
#include "World.hpp"
int main() {
    system("cls");

    bool running = true;

    std::cout << "Wpisz szerokosc, a nastepnie wysokosc planszy:";
     int width, height;
    std::cin >> width >> height;

    World world(width, height);
    while (running) {
        world.rndr.draw();
        Sleep(3000);
    }
}
