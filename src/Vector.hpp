#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <math.h>

#include <utility>

#define PI 3.14159265
#define TYPE int
class Vector {
   public:
    TYPE x;
    TYPE y;
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

    Vector(TYPE x, TYPE y) {
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

    Vector operator*(const double& right) { return this->rescale(right); }

    Vector operator*(const Vector& right) { return this->rescale(right); }

    Vector& operator*=(const double& right) {
        return *this = this->rescale(right);
    }

    Vector& operator*=(const Vector& right) {
        return *this = this->rescale(right);
    }

    Vector difference(Vector other) { return Vector(x - other.x, y - other.y); }

    Vector invert() { return Vector(-x, -y); }

    Vector invertX() { return Vector(-x, y); }

    Vector invertY() { return Vector(x, -y); }

    double magnitude() { return sqrt(x * x + y * y); }

    Vector rescale(double factor) {
        return Vector(static_cast<TYPE>(x * factor),
                      static_cast<TYPE>(y * factor));
    }

    Vector rescale(Vector other) {
        double ratio = other.magnitude() / this->magnitude();
        return rescale(ratio);
    }

    Vector add(Vector other) { return Vector(x + other.x, y + other.y); }

    Vector addX(TYPE x_) { return Vector(x + x_, y); }

    Vector addY(TYPE y_) { return Vector(x, y + y_); }
};

#endif
