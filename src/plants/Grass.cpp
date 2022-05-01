#include "Grass.hpp"

int Grass::counter = 0;

Plant* Grass::getSapling() { return new Grass(world); }