#include "Wolf.hpp"

int Wolf::counter = 0;

Animal* Wolf::giveBirth() { return new Wolf(world); }