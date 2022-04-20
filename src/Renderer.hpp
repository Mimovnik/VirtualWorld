#ifndef RENDERER_H
#define RENDERER_H

class Renderer {
    char* terrain = nullptr;
    int width, height;

   public:
    Renderer() {}
    Renderer(int width, int height);

    ~Renderer();

    Renderer& operator=(Renderer&& other) noexcept;

    char getCell(int x, int y);

    void draw();
};

#endif