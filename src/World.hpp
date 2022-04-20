#ifndef WORLD_H
#define WORLD_H

#include "Renderer.hpp"

class World {
     int width, height;

   public:
    Renderer rndr;
    World( int width,  int heigth);
};

#endif