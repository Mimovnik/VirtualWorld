#include "Sheep.hpp"

int Sheep::counter = 0;

Animal* Sheep::giveBirth() { return new Sheep(world); }