#include "Animal.hpp"

#include "World.hpp"

Animal::Animal() {}

Animal::Animal(World* world, int strength, int initiative, char skin)
    : Organism(world, strength, initiative, skin) {}

void Animal::move(int direction) {
    switch (direction) {
        case 0:
            if (position.x + 1 < world->getWidth()) {
                position.x += 1;
            }
            break;
        case 1:
            if (position.x > 0) {
                position.x -= 1;
            }
            break;
        case 2:
            if (position.y + 1 < world->getHeight()) {
                position.y += 1;
            }
            break;
        case 3:
            if (position.y > 0) {
                position.y -= 1;
            }
            break;
    }
}

void Animal::action() {
    int direction = rand() % 4;
    move(direction);
    // Organism beeing attacked by this Animal
    Organism* defender = world->getColliderWith(this);
    if (defender != nullptr) {
        collide(defender);
    }
};

void Animal::collide(Organism* other){

};