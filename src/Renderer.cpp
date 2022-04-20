#include "Renderer.hpp"

#include <iostream>

Renderer::Renderer(int width_, int height_) {
    this->width = width_;
    this->height = height_;
    this->terrain = new char[width * height];
    std::memset(terrain, 'g', width * height);
}

Renderer::~Renderer() {
    if (terrain != nullptr) {
        delete[] terrain;
    }
}

Renderer& Renderer::operator=(Renderer&& other) noexcept {
    if (this == &other) {
        return *this;
    }
    if (terrain != nullptr) {
        delete[] terrain;
    }
    terrain = std::exchange(other.terrain, nullptr);
    width = std::exchange(other.width, 0);
    height = std::exchange(other.height, 0);
    return *this;
}

char Renderer::getCell(int x, int y) {
    if (x > width || x < 0) {
        throw "Bad x coordinate";
    }
    if (y > height || y < 0) {
        throw "Bad y coordinate";
    }
    return terrain[width * y + x];
}

void Renderer::draw() {
    system("cls");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::cout << getCell(x, y);
        }
        std::cout << std::endl;
    }
}