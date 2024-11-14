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
    void Print() const override 
    {
        std::cout << "Velocity: (" << dx << ", " << dy << ")\n";

    }

};

class Position : public Component {
public:
    float x, y;

    Position(float x, float y) : x(x), y(y) {}

    // Implement Print function for Position
    void Print() const override 
    {
        std::cout << "Position: (" << x << ", " << y << ")\n";
    }

    void RectCollisions(float &dx, float &dy, float padding)
    {

        if (x + padding >= WINDOW_WIDTH)
        {
            x = WINDOW_WIDTH - padding;
            dx *= -1;
        }
        else if (x <= 0)
        {
            x = padding;
            dx *= -1;
        }
         
        if (y + padding >= WINDOW_HEIGHT)
        {
            y = WINDOW_HEIGHT - padding;
            dy *= -1;
        }
        else if (y - padding <= 0) 
        {
            y = padding;
            dy *= -1;
        }
    }

    bool DetectCollisions(sf::FloatRect selfCollider, sf::FloatRect otherCollider) 
    {

          return selfCollider.intersects(otherCollider);
    }
};

class Size : public Component 
{
public:
    float width, height;

    Size(float width, float height) : width(width), height(height) {}

    // Implement Print function for Size
    void Print() const override 
    {
        std::cout << "Size: (" << width << ", " << height << ")\n";
    }
};

class Drawable : public Component 
{
public:

    bool isDrawn;

    Drawable(bool isDrawn) : isDrawn(isDrawn) {};

    void Draw(sf::Shape& shape, float x, float y,sf::Color color, sf::RenderWindow& window) 
    {
        if (!isDrawn) 
        {
            return;
        }
        shape.setPosition(sf::Vector2f(x,y));
        shape.setFillColor(color);

        window.draw(shape);
    }

    void Print() const override 
    {
        std::cout << "Drawable: (" << isDrawn << ")\n";

    }
};

class Life 
{
    float Health;
    bool IsAlive;
};