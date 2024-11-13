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
		paddleComponent.AddComponent(Velocity{ PADDLE_DEFAULT_VELOCITY, .0f }, "Velocity");

		paddleComponent.AddComponent(Position{ PADDLE_DEFAULT_X , PADDLE_DEFAULT_Y }, "Position");

		paddleComponent.AddComponent(Size{ PADDLE_WIDTH,PADDLE_HEIGHT }, "Size");

		/*Component* component = paddleComponent.GetComponent<Position>("Position");

		paddleComponent.DeleteComponent<Position>("Position");*/
	}

	void Init();
	void Draw(sf::RenderWindow& window);
	void Move(int xDir);
	void BorderCollision();
	void Collision();
private:

	std::vector<std::pair<std::string, std::unique_ptr<Component>>> componentArr;
	

	Size* paddleSize;
	Velocity* paddleVelocity;
	Position* paddlePosition;
};


class Ball : public Entity 
{
public:
	ComponentManager<Component> ballComponent;

	Ball() 
	{
		ballComponent.AddComponent(Velocity{ BALL_DEFAULT_VELOCITY, BALL_DEFAULT_VELOCITY }, "Velocity");

		ballComponent.AddComponent(Position{ BALL_DEFAULT_X , BALL_DEFAULT_Y }, "Position");

		ballComponent.AddComponent(Size{ BALL_RADIUS,BALL_RADIUS }, "Size");
	}

	void Init();


private:
	
	std::vector<std::pair<std::string, std::unique_ptr<Component>>> componentArr;


	Size* ballSize;
	Velocity* ballVelocity;
	Position* ballPosition;

};