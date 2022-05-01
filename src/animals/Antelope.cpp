#include "Antelope.hpp"

#include "../World.hpp"
#include "Fox.hpp"

int Antelope::counter = 0;


Animal* Antelope::giveBirth() { return new Antelope(world); }

void Antelope::escape(){
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
    move(direction);
}


void Antelope::takeHit(Organism* attacker) {
    if (rand() % 2) {
        world->writeEvent(name + " escapes from a fight with " +
                          attacker->getName() + "\n");
        escape();
    } else {
        world->writeEvent(name + " took a hit from " + attacker->getName() +
                          " and died\n");
        die();
    }
};