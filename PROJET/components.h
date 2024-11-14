#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "constants.h"

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

    void Invert(float& dx, float& dy)
    {
        dy *= -1;
        dx *= -1;
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

    void BorderCollision(float &dx, float &dy, float padding)
    {
        if (x + padding >= WINDOW_WIDTH)
        {
            x = WINDOW_WIDTH - padding;
            dy *= -1;
            dx *= -1;
        }
        else if (x - padding <= 0)
        {
            x = padding;
            dy *= -1;
            dx *= -1;
        }

        if (y + padding >= WINDOW_HEIGHT)  // Object reached the bottom
        {
            y = WINDOW_HEIGHT - padding;  // Set position to just above the boundary
            dy *= -1;
            dx *= -1;
        }
        else if (y - padding <= 0)  // Object reached the top
        {
            y = padding;  // Set position to just below the boundary
            dy *= -1;
            dx *= -1;
        }
    }

    bool DetectCollisions(sf::FloatRect selfCollider, sf::FloatRect otherCollider) 
    {
        if (selfCollider.intersects(otherCollider))
        {
            return true;
        }
    }
};

class Size : public Component 
{
public:
    float width, height;

    Size(float width, float height) : width(width), height(height) {}

    // Implement Print function for Size
    void Print() const override {
        std::cout << "Size: (" << width << ", " << height << ")\n";
    }
};