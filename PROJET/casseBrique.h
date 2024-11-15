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

	Position* GetPosition();
	sf::RectangleShape GetRect();
	sf::FloatRect GetCollider();
	float GetX();
	float GetY();

	Position* paddlePosition;

private:

	//std::vector<std::pair<std::string, std::unique_ptr<Component>>> componentArr;
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
	Position* ballPosition;


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
	//std::vector<std::pair<std::string, std::unique_ptr<Component>>> componentArr;
	
	sf::FloatRect ballBounds;
	sf::CircleShape ball;

	Size* ballSize;
	Velocity* ballVelocity;
	Drawable* ballDrawing;
};

class Brick
{
public:
	ComponentManager<Brick> brickComponent;
	
	std::vector<Brick> brickArray;
	Brick(float x, float y) : x(x), y(y), isDrawn(true)
	{
		brickRect.setSize(sf::Vector2f(BRICK_WIDTH, BRICK_HEIGHT));
		brickRect.setPosition(x, y);
		brickRect.setFillColor(sf::Color::Green);  // Set the color of the brick
	}

	void Init();


	void Draw();
	void Grid(std::vector<Brick>& ballArray);

	void Update(sf::RenderWindow& widnow, std::vector<Brick>& ballArray);


	void SetPosition(float newX, float newY)
	{
		x = newX;
		y = newY;
		brickRect.setPosition(sf::Vector2f(x, y));  // Update the rectangle position
	}

private:
	float x, y;
	sf::Vector2f position;
	sf::Color color;
	sf::RectangleShape brickRect;
	bool isDestroyed;
	bool isDrawn;
};

class Game 
{
public:
	Game() : brick(0.f, 0.f) // Initialize brick with default x, y values
	{
		paddle = Paddle();
		ball = Ball();
	}
		;
	void Init();
	void Reset(Paddle paddle, std::vector<Paddle>& test);

	void Update(sf::RenderWindow& window, float deltaTime);

private:

	std::vector<Brick> brickArray{};

	Paddle paddle;
	Ball ball;
	Brick brick;

};