#include "World.hpp"

#include <stdlib.h>

#include <algorithm>
#include <iostream>

#include "animals/Human.hpp"
#include "animals/Wolf.hpp"
#include "plants/Grass.hpp"

World::World(int width, int height) {
    this->width = width;
    this->height = height;
    this->terrain = new char[width * height];
    std::memset(terrain, '.', width * height);
    int organismsNumber = width * height / 100 + 1;
    organismsNumber = 3;
    organisms.push_back(std::make_unique<Human>(Human(this)));
    for (int i = 0; i < organismsNumber; i++) {
        if (i % 2) {
            organisms.push_back(std::make_unique<Wolf>(Wolf(this)));
        } else {
            organisms.push_back(std::make_unique<Grass>(Grass(this)));
        }
    }
}

char* World::getCell(int x, int y) {
    char errorMsg[128];
    if (x > width || x < 0) {
        sprintf_s(errorMsg, "Bad x coordinate: %d", x);
        throw errorMsg;
    }
    if (y > height || y < 0) {
        sprintf_s(errorMsg, "Bad y coordinate: %d", y);
        throw errorMsg;
    }
    return &terrain[width * y + x];
}

char* World::getCell(Vector position) {
    char errorMsg[128];
    if (position.x > width || position.x < 0) {
        sprintf_s(errorMsg, "Bad x coordinate: %d", position.x);
        throw errorMsg;
    }
    if (position.y > height || position.y < 0) {
        sprintf_s(errorMsg, "Bad y coordinate: %d", position.y);
        throw errorMsg;
    }
    return &terrain[width * position.y + position.x];
}

void World::draw() {
    std::memset(terrain, '.', width * height);
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
        *getCell(organisms[i]->getPos()) = organisms[i]->getSkin();
    }
}

void World::sortOrganisms() { std::sort(organisms.begin(), organisms.end()); }

void World::makeTurns() {
    sortOrganisms();
    for (int i = 0; i < organisms.size(); i++) {
        organisms[i]->action();
    }
}

Vector World::getRandomEmptyPos() {
    Vector pos(rand() % width, rand() % height);
    for (int i = 0; i < organisms.size(); i++) {
        if (pos == organisms[i]->getPos()) {
            pos.x = rand() % width;
            pos.y = rand() % height;
            i = 0;
        }
    }
    return pos;
}

int World::getSize() const { return width * height; }
int World::getWidth() const { return width; }
int World::getHeight() const { return height; }