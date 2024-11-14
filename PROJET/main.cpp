#include "ECS.h"
#include <SFML/Graphics.hpp>
#include <vector>

#include "casseBrique.h"

int main() 
{
    sf::Clock clock;

    Paddle paddle;
    Ball ball;
    //paddle.Init(components);

    //ComponentManager test;

    paddle.Init();
    ball.Init();

    sf::RenderWindow window(sf::VideoMode(WINDOW_HEIGHT,WINDOW_WIDTH), "Casse Brique");

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //ball.Draw(window);
        paddle.Update(window, sf::Keyboard::isKeyPressed(sf::Keyboard::D) - sf::Keyboard::isKeyPressed(sf::Keyboard::Q));
        ball.Update(deltaTime, paddle, window);

        //window.draw(shape);
        window.display();
    }
	return 0;
}