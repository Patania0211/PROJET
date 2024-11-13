#include "casseBrique.h"

void Paddle::Init()
{
	//Get components
	Component* paddleSizeBase = paddleComponent.GetComponent<Size>("Size");
	paddleSize = dynamic_cast<Size*>(paddleSizeBase);


	Component* paddlePositionBase = paddleComponent.GetComponent<Position>("Position");
	paddlePosition = dynamic_cast<Position*>(paddlePositionBase);
	
	Component* paddleVelocityBase = paddleComponent.GetComponent<Velocity>("Velocity");
	paddleVelocity = dynamic_cast<Velocity*>(paddleVelocityBase);
	
};

void Paddle::Draw(sf::RenderWindow& window)
{
	if (!paddleSize)
	{
		std::cout << "NO paddle size component" << std::endl;
		return;
	}

	sf::RectangleShape paddle(sf::Vector2f(paddleSize->width, paddleSize->height));
	

	if (!paddlePosition)
	{
		std::cout << "NO paddle position component" << std::endl;
		return;
	}

	if (!paddleVelocity)
	{
		std::cout << "NO paddle velocity component" << std::endl;
		return;
	}

	paddle.setPosition(sf::Vector2f(paddlePosition->x, paddlePosition->y));


	paddle.setFillColor(sf::Color::Blue);

	window.draw(paddle);
	return;
}


void Paddle::Move(int xDir) 
{
	paddlePosition->x += xDir * DEFAULT_VELOCITY_CLAMP;

	BorderCollision();
	return;
}


void Paddle::BorderCollision() 
{

	if (paddlePosition->x + PADDING > WINDOW_WIDTH )
	{
		paddlePosition->x = WINDOW_WIDTH - PADDING;
		paddleVelocity->dx = 0;

	}
	if (paddlePosition->x - PADDING < 0)
	{
		paddlePosition->x = 0 + PADDING;
		paddleVelocity->dx = 0;

	}
	return;
}

void Paddle::Collision() 
{
	return;
}

void Ball::Init() 
{
	//Get components
	Component* ballSizeBase = ballComponent.GetComponent<Size>("Size");
	ballSize = dynamic_cast<Size*>(ballSizeBase);


	Component* ballPositionBase = ballComponent.GetComponent<Position>("Position");
	ballPosition = dynamic_cast<Position*>(ballPositionBase);

	Component* ballVelocityBase = ballComponent.GetComponent<Velocity>("Velocity");
	ballVelocity = dynamic_cast<Velocity*>(ballVelocityBase);
}

void Ball::Move() 
{
	ballPosition->x += ballVelocity->dx;
	ballPosition->y += ballVelocity->dy;
}

