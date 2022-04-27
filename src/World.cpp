#include "World.hpp"

#include <stdlib.h>

#include <algorithm>
#include <iostream>

#include "animals/Antelope.hpp"
#include "animals/Fox.hpp"
#include "animals/Human.hpp"
#include "animals/Sheep.hpp"
#include "animals/Turtle.hpp"
#include "animals/Wolf.hpp"
#include "plants/Dandelion.hpp"
#include "plants/Grass.hpp"
#include "plants/Guarana.hpp"
#include "plants/PineBorscht.hpp"
#include "plants/Wolfberry.hpp"

World::World(int width, int height) {
    this->width = width;
    this->height = height;
    int size = width * height;
    this->terrain = new char[size];
    std::memset(terrain, '.', size);
    int organismsNumber = size / 100;
    organisms.push_back(new Human(this));
    for (int i = 0; i < organismsNumber; i++) {
        int whichOne = rand() % 10;
        switch (whichOne) {
            case 0:
                organisms.push_back(new Antelope(this));
                break;
            case 1:
                organisms.push_back(new Fox(this));
                break;
            case 2:
                organisms.push_back(new Sheep(this));
                break;
            case 3:
                organisms.push_back(new Turtle(this));
                break;
            case 4:
                organisms.push_back(new Wolf(this));
                break;
            case 5:
                organisms.push_back(new Dandelion(this));
                break;
            case 6:
                organisms.push_back(new Grass(this));
                break;
            case 7:
                organisms.push_back(new Guarana(this));
                break;
            case 8:
                organisms.push_back(new PineBorscht(this));
                break;
            case 9:
                organisms.push_back(new Wolfberry(this));
                break;
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

bool compareOrganisms(Organism* left, Organism* right) {
    if (left->initiative != right->initiative) {
        return left->initiative > right->initiative;
    }
    return left->birthDate < right->birthDate;
}

void World::sortOrganisms() {
    std::sort(organisms.begin(), organisms.end(), compareOrganisms);
}

void World::makeTurns() {
    sortOrganisms();
    for (int i = 0; i < organisms.size(); i++) {
        organisms[i]->action();
    }
}

    void World::removeDeadOrganisms(){
        for(int i = 0; i < organisms.size();i++){
            if(organisms[i]->isDead()){
                organisms.erase(organisms.begin() + i);
            }
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

Organism* World::getColliderWith(Organism* attacker) {
    for (int i = 0; i < organisms.size(); i++) {
        // return first organism on the same position as attacker's
        // as long as it isn't the attacker itself
        if (attacker->getPos() == organisms[i]->getPos() &&
            attacker->getBirthDate() != organisms[i]->getBirthDate()) {
            return organisms[i];
        }
    }
    return nullptr;
}

int World::getSize() const { return width * height; }
int World::getWidth() const { return width; }
int World::getHeight() const { return height; }