#include "Dandelion.hpp"

int Dandelion::counter = 0;

Plant* Dandelion::getSapling() { return new Dandelion(world); }