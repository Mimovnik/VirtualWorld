#include "World.hpp"

World::World( int width, int height) {
    this->width = width;
    this->height = height;
    this->rndr = Renderer(width, height);
}