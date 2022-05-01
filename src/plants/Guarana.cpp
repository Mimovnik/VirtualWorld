#include "Guarana.hpp"

int Guarana::counter = 0;

Plant* Guarana::getSapling() { return new Guarana(world); }