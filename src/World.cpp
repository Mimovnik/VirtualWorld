#include "World.hpp"

#include <iostream>

World::World(int width, int height) {
    this->width = width;
    this->height = height;
    this->terrain = new char[width * height];
    std::memset(terrain, '.', width * height);
    int organismsNumber = width * height / 5 + 1;
    for (int i = 0; i < organismsNumber; i++) {
    }
}

char* World::getCell(int x, int y) {
    if (x > width || x < 0) {
        throw "Bad x coordinate";
    }
    if (y > height || y < 0) {
        throw "Bad y coordinate";
    }
    return &terrain[width * y + x];
}

char* World::getCell(Vector position) {
    if (position.x > width || position.x < 0) {
        throw "Bad x coordinate";
    }
    if (position.y > height || position.y < 0) {
        throw "Bad y coordinate";
    }
    return &terrain[width * position.y + position.x];
}

void World::draw() {
    system("cls");
    renderOrganisms();
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::cout << *getCell(x, y);
        }
        std::cout << std::endl;
    }
}
void World::renderOrganisms() {
    for (int i = 0; i < organisms.size(); i++) {
        *getCell(organisms[i].getPos()) = organisms[i].getSkin();
    }
}