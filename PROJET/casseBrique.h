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

	sf::RectangleShape GetRect();
	sf::FloatRect GetCollider();

private:

	std::vector<std::pair<std::string, std::unique_ptr<Component>>> componentArr;
	

	Size* paddleSize;
	Velocity* paddleVelocity;
	Position* paddlePosition;

	sf::RectangleShape paddle;
	sf::FloatRect collider;
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

	void Move(float deltaTime);

	void Update(float deltaTime, Paddle& paddle);

	sf::CircleShape GetCircle();
	void Draw(sf::RenderWindow& window);

	void HandleCollisions(Paddle& paddle);


private:
	//sf::CircleShape ball;

	std::vector<std::pair<std::string, std::unique_ptr<Component>>> componentArr;
	
	sf::FloatRect collider;


	Size* ballSize;
	Velocity* ballVelocity;
	Position* ballPosition;

};