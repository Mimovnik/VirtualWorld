#include "Fox.hpp"

#include "../World.hpp"

int Fox::counter = 0;

Animal* Fox::giveBirth() { return new Fox(world); }

int Fox::getDirection() {
    int direction;
    std::vector<int> possibleDirs;
    Organism* right = world->getOrganismByPos(position.addX(1));
    Organism* left = world->getOrganismByPos(position.addX(-1));
    Organism* down = world->getOrganismByPos(position.addY(1));
    Organism* up = world->getOrganismByPos(position.addY(-1));
    if (right != nullptr) {
        if (!right->isStronger(this)) {
            possibleDirs.push_back(0);
        }
    } else {
        possibleDirs.push_back(0);
    }
    if (left != nullptr) {
        if (!left->isStronger(this)) {
            possibleDirs.push_back(1);
        }
    } else {
        possibleDirs.push_back(1);
    }
    if (down != nullptr) {
        if (!down->isStronger(this)) {
            possibleDirs.push_back(2);
        }
    } else {
        possibleDirs.push_back(2);
    }
    if (up != nullptr) {
        if (!up->isStronger(this)) {
            possibleDirs.push_back(3);
        }
    } else {
        possibleDirs.push_back(3);
    }

    if (possibleDirs.empty()) {
        direction = -1;
    } else {
        direction = possibleDirs[rand() % possibleDirs.size()];
    }
    possibleDirs.clear();
    possibleDirs.shrink_to_fit();
    return direction;
}