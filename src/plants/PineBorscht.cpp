#include "PineBorscht.hpp"

int PineBorscht::counter = 0;

bool PineBorscht::isStronger(Organism* other) { return true; }

Plant* PineBorscht::getSapling() { return new PineBorscht(world); }