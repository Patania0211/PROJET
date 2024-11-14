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

	Component* paddleDrawingBase = paddleComponent.GetComponent<Drawable>("Drawable");
	paddleDrawing = dynamic_cast<Drawable*>(paddleDrawingBase);

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

	if (!paddleDrawing) 
	{
		std::cout << "NO paddle drawable component" << std::endl;
		return;
	}
	paddleDrawing->isDrawn = true;
};
void Paddle::Update(sf::RenderWindow& window, int xDir)
{
	Move(xDir);

	paddlePosition->RectCollisions(paddleVelocity->dx, paddleVelocity->dy, PADDING);

	paddle = GetRect();
	paddleDrawing->Draw(paddle, paddlePosition->x, paddlePosition->y, sf::Color::Yellow, window);

	ClampRight();
	return;
}
void Paddle::ClampRight() 
{
	if (paddlePosition->x + paddleSize->width >= WINDOW_WIDTH - PADDING) {
		paddlePosition->x = WINDOW_WIDTH - paddleSize->width - PADDING;
		paddleVelocity->dx = 0;
	}
}
void Paddle::Move(int xDir) 
{
	paddlePosition->x += xDir * DEFAULT_VELOCITY_CLAMP ;

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

	Component* ballDrawingBase = ballComponent.GetComponent<Drawable>("Drawable");
	ballDrawing = dynamic_cast<Drawable*>(ballDrawingBase);


	if (!ballSize)
	{
		std::cout << "NO ball size component" << std::endl;
		return;
	}

	if (!ballPosition)
	{
		std::cout << "NO ball position component" << std::endl;
		return;
	}

	if (!ballVelocity)
	{
		std::cout << "NO ball velocity component" << std::endl;
		return;
	}

	if (!ballDrawing)
	{
		std::cout << "NO ball drawable component" << std::endl;
		return;
	}

	ballDrawing->isDrawn = true;

	ball.setOrigin(sf::Vector2f(BALL_RADIUS / 2, BALL_RADIUS / 2));

	ball.setRadius(BALL_RADIUS);

}

void Ball::Move(float deltaTime)
{
	ballPosition->x += ballVelocity->dx * deltaTime;
	ballPosition->y += ballVelocity->dy * deltaTime;
}

void Ball::Update(float deltaTime, Paddle& paddle, sf::RenderWindow& window)
{

	Move(deltaTime);
	ballPosition->RectCollisions(ballVelocity->dx, ballVelocity->dy, BALL_RADIUS/2);
	ballDrawing->Draw(ball, ballPosition->x, ballPosition->y, sf::Color::Magenta, window);


	//ballPosition->Print();
	Bounce(paddle.GetCollider());

	ballBounds = ball.getGlobalBounds();
	return;

}

void Ball::Bounce(sf::FloatRect paddleBounds) 
{

	sf::FloatRect ballBounds(ballPosition->x, ballPosition->y, BALL_RADIUS * 2, BALL_RADIUS * 2);

	if (ballBounds.intersects(paddleBounds)) 
	{

		if (ballBounds.top + ballBounds.height <= paddleBounds.top + 10) 
		{ 
			ballVelocity->dy = -abs(ballVelocity->dy);
		}
		// If the ball hits the bottom part of the paddle (y-axis)
		else if (ballBounds.top >= paddleBounds.top + paddleBounds.height - 10) 
		{
			ballVelocity->dy = abs(ballVelocity->dy);
		}

		else 
		{
			if (ballVelocity->dx > 0) 
			{
				ballVelocity->dx = -abs(ballVelocity->dx);
			}
			else 
			{
				ballVelocity->dx = abs(ballVelocity->dx);
			}
		}
	}
}


