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

        ball.Update(deltaTime, paddle);
        //ball.Move(deltaTime);
        //ball.HandleCollisions(paddle);

        paddle.Move(sf::Keyboard::isKeyPressed(sf::Keyboard::D) - sf::Keyboard::isKeyPressed(sf::Keyboard::Q));
        
        window.clear();
        ball.Draw(window);
        paddle.Draw(window);

        //window.draw(shape);
        window.display();
    }
	return 0;
}