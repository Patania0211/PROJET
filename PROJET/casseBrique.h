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

		paddleComponent.AddComponent(Drawable{ isDrawn }, "Drawable");

	}

	void Init();
	void Update(sf::RenderWindow& window, int xDir);

	void ClampRight();
	void Move(int xDir);

	sf::RectangleShape GetRect();
	sf::FloatRect GetCollider();
	float GetX();
	float GetY();

	Position* paddlePosition;

private:

	std::vector<std::pair<std::string, std::unique_ptr<Component>>> componentArr;
	bool isDrawn;

	Size* paddleSize;
	Velocity* paddleVelocity;
	Drawable* paddleDrawing;

	sf::RectangleShape paddle;
	sf::FloatRect collider;
};


class Ball : public Entity 
{
public:
	ComponentManager<Component> ballComponent;

	Ball() 
	{
		ballComponent.AddComponent(Velocity{ BALL_DEFAULT_VELOCITY_X, BALL_DEFAULT_VELOCITY_Y }, "Velocity");

		ballComponent.AddComponent(Position{ BALL_DEFAULT_X , BALL_DEFAULT_Y }, "Position");

		ballComponent.AddComponent(Size{ BALL_RADIUS,BALL_RADIUS }, "Size");

		ballComponent.AddComponent(Drawable{isDrawn}, "Drawable");
	}


	void Init();

	void Move(float deltaTime);

	void Update(float deltaTime, Paddle& paddle, sf::RenderWindow& window);

	void Bounce(sf::FloatRect paddleBounds);

	void Bounce(Paddle& paddle);


private:
	//sf::CircleShape ball;
	bool isDrawn;
	std::vector<std::pair<std::string, std::unique_ptr<Component>>> componentArr;
	
	sf::FloatRect ballBounds;
	sf::CircleShape ball;

	Size* ballSize;
	Velocity* ballVelocity;
	Position* ballPosition;
	Drawable* ballDrawing;
};


class Brick : public Entity
{
public:
	ComponentManager<Component> brickComponent;

	Brick()
	{
		brickComponent.AddComponent(Position{ PADDLE_DEFAULT_X , PADDLE_DEFAULT_Y }, "Position");

		brickComponent.AddComponent(Size{ PADDLE_WIDTH,PADDLE_HEIGHT }, "Size");

		brickComponent.AddComponent(Drawable{ isDrawn }, "Drawable");

	}

	void Init();
	void Update(sf::RenderWindow& window);


private:

	std::vector<std::pair<std::string, std::unique_ptr<Component>>> componentArr;
	bool isDrawn;

	Size* brickSize;
	Velocity* brickVelocity;
	Drawable* brickDrawing;
	Position* position;

	sf::RectangleShape brick;
	sf::FloatRect collider;
};