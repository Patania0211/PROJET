#include "ECS.h"
#include <SFML/Graphics.hpp>
#include <vector>

#include "casseBrique.h"

int main() 
{


    Paddle paddle;
    //paddle.Init(components);

    //ComponentManager test;


    sf::RenderWindow window(sf::VideoMode(WINDOW_HEIGHT,WINDOW_WIDTH), "Casse Brique");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        paddle.Draw(window);
        //window.draw(shape);
        window.display();
    }
	return 0;
}