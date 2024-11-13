#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <SFML/Graphics.hpp>

#include "ECS.h"
#include "components.h"
#include "constants.h"

class Paddle : public Entity
{
public:
	ComponentManager<Component> paddleComponent;

	Paddle()
	{
		paddleComponent.AddComponent(Velocity{ 10.f, .0f }, "Velocity");

		paddleComponent.AddComponent(Position{ WINDOW_WIDTH / 2 , 12.f}, "Position");

		paddleComponent.AddComponent(Size{ 10,20 }, "Size");

		/*Component* component = paddleComponent.GetComponent<Position>("Position");

		paddleComponent.DeleteComponent<Position>("Position");*/
	}

	void Draw(sf::RenderWindow& window);

private:
	std::vector<std::pair<std::string, std::unique_ptr<Component>>> componentArr;
};