#include "Wolfberry.hpp"

int Wolfberry::counter = 0;

bool Wolfberry::isStronger(Organism* other) { return true; }

Plant* Wolfberry::getSapling() { return new Wolfberry(world); }