#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <math.h>

#include <utility>

#define PI 3.14159265
#define TYPE int
class Vector {
   public:
    int x;
    int y;
    const static Vector ZERO;

    Vector() {
        x = 0;
        y = 0;
    }

    Vector(const Vector& other) {
        this->x = other.x;
        this->y = other.y;
    }

    Vector(Vector&& other) {
        this->x = std::move(other.x);
        this->y = std::move(other.y);
    }

    Vector(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Vector& operator=(const Vector& right) {
        Vector tmp = right;
        std::swap(x, tmp.x);
        std::swap(y, tmp.y);
        return *this;
    }

    Vector& operator=(Vector&& right) {
        std::swap(x, right.x);
        std::swap(y, right.y);
        return *this;
    }

    Vector operator+(const Vector& right) { return this->add(right); }

    Vector& operator+=(const Vector& right) { return *this = this->add(right); }

    Vector operator-(const Vector& right) { return this->difference(right); }

    Vector& operator-=(const Vector& right) {
        return *this = this->difference(right);
    }

    Vector operator*(const int& right) { return this->rescale(right); }

    Vector operator*(const Vector& right) { return this->rescale(right); }

    Vector& operator*=(const int& right) {
        return *this = this->rescale(right);
    }

    Vector& operator*=(const Vector& right) {
        return *this = this->rescale(right);
    }

    static Vector fromAngle(int length, int angle) {
        int x = length * sin(angle * PI / 180);
        int y = length * cos(angle * PI / 180);
        return Vector(x, y);
    }

    Vector difference(Vector other) { return Vector(x - other.x, y - other.y); }

    Vector invert() { return Vector(-x, -y); }

    Vector invertX() { return Vector(-x, y); }

    Vector invertY() { return Vector(x, -y); }

    int magnitude() { return sqrt(x * x + y * y); }

    Vector rescale(int factor) { return Vector(x * factor, y * factor); }

    Vector rescale(Vector other) {
        int ratio = other.magnitude() / this->magnitude();
        return rescale(ratio);
    }

    Vector add(Vector other) { return Vector(x + other.x, y + other.y); }

    Vector addX(int x_) { return Vector(x + x_, y); }

    Vector addY(int y_) { return Vector(x, y + y_); }

    Vector setAngle(int angle) {
        return Vector(magnitude() * sin(angle * PI / 180),
                      magnitude() * cos(angle * PI / 180));
    }

    int getAngle() {
        if (magnitude() == 0) return 0;
        return (180 / PI) * atan2(x, y);
    }

    Vector rotate(int angle) { return setAngle(getAngle() + angle); }
};

#endif
