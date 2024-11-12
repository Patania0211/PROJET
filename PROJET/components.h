#pragma once
#include <iostream>

class Component {
public:
    virtual ~Component() = default;  // Virtual destructor for polymorphism
    virtual void Print() const = 0;  // Pure virtual function for printing component data
};

class Velocity : public Component {
public:
    float dx, dy;

    Velocity(float dx, float dy) : dx(dx), dy(dy) {}

    // Implement Print function for Velocity
    void Print() const override {
        std::cout << "Velocity: (" << dx << ", " << dy << ")\n";
    }
};

class Position : public Component {
public:
    float x, y;

    Position(float x, float y) : x(x), y(y) {}

    // Implement Print function for Position
    void Print() const override {
        std::cout << "Position: (" << x << ", " << y << ")\n";
    }
};

class Size : public Component {
public:
    float width, height;

    Size(float width, float height) : width(width), height(height) {}

    // Implement Print function for Size
    void Print() const override {
        std::cout << "Size: (" << width << ", " << height << ")\n";
    }
};
