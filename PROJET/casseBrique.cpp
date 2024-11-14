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

	if (!paddleSize)
	{
		std::cout << "NO paddle size component" << std::endl;
		return;
	}

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

	
};
void Paddle::Draw(sf::RenderWindow& window)
{

	paddle = GetRect();

	paddle.setPosition(sf::Vector2f(paddlePosition->x, paddlePosition->y));

	paddle.setFillColor(sf::Color::Blue);

	collider = paddle.getGlobalBounds();


	window.draw(paddle);

	return;
}

void Paddle::Move(int xDir) 
{
	paddlePosition->x += xDir * DEFAULT_VELOCITY_CLAMP ;

	paddlePosition->BorderCollision(paddleVelocity->dx, paddleVelocity->dy, PADDING);
	return;
}

sf::RectangleShape Paddle::GetRect()
{
	return sf::RectangleShape(sf::Vector2f(paddleSize->width, paddleSize->height));
}

sf::FloatRect Paddle::GetCollider()
{
	return sf::FloatRect(paddle.getGlobalBounds());
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

	if (!ballSize)
	{
		std::cout << "NO paddle size component" << std::endl;
		return;
	}

	if (!ballPosition)
	{
		std::cout << "NO paddle position component" << std::endl;
		return;
	}

	if (!ballVelocity)
	{
		std::cout << "NO paddle velocity component" << std::endl;
		return;
	}
}

void Ball::Move(float deltaTime)
{
	ballPosition->x += ballVelocity->dx * deltaTime;
	ballPosition->y += ballVelocity->dy * deltaTime;


}

void Ball::Update(float deltaTime, Paddle& paddle)
{
	Move(deltaTime);
	ballPosition->BorderCollision(ballVelocity->dx, ballVelocity->dy, BALL_RADIUS);
	HandleCollisions(paddle);
}

sf::CircleShape GetCircle() 
{
	return sf::CircleShape (BALL_RADIUS);
}
void Ball::Draw(sf::RenderWindow& window)
{

	sf::CircleShape ball(BALL_RADIUS);

	ball.setOrigin(BALL_RADIUS / 2, BALL_RADIUS / 2);

	ball.setPosition(sf::Vector2f(ballPosition->x, ballPosition->y));

	ball.setFillColor(sf::Color::Magenta);

	collider = ball.getGlobalBounds();

	window.draw(ball);

	return;
}

void Ball::HandleCollisions(Paddle& paddle) 
{
	if (ballPosition->DetectCollisions(collider, paddle.GetCollider()))
	{
		ballVelocity->Invert(ballVelocity->dx, ballVelocity->dy);

	}
}

