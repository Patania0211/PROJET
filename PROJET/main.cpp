#include "ECS.h"
#include <SFML/Graphics.hpp>
#include <vector>

#include "casseBrique.h"

int main() 
{
    sf::Clock clock;

    Game game;
    game.Init();

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "Casse Brique");

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
        game.Update(window, deltaTime);
        window.display();
    }
	return 0;
}