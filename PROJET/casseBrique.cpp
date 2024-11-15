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

Position* Paddle::GetPosition()
{
	return dynamic_cast<Position*>(paddleComponent.GetComponent<Position>("Position"));
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
	ballDrawing->Draw(ball, ballPosition->x, ballPosition->y, sf::Color::Red, window);


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



void Brick::Init() 
{
	//Component* brickSizeBase = brickComponent.GetComponent<Size>("Size");
	//brickSize = dynamic_cast<Size*>(brickSizeBase);

	///*Component* brickPositionBase = brickComponent.GetComponent<Position>("Position");
	//brickPosition = dynamic_cast<Position*>(brickPositionBase);

	//Component* brickDrawingBase = brickComponent.GetComponent<Drawable>("Drawable");
	//brickDrawing = dynamic_cast<Drawable*>(brickDrawingBase);*/

	//std::shared_ptr<Position> brickPositionBase = brickComponent.GetComponent<Position>("Position");
	//brickPosition = brickPositionBase.get();  // No need to dynamic_cast if you are using shared_ptr

	//std::shared_ptr<Drawable> brickDrawingBase = brickComponent.GetComponent<Drawable>("Drawable");
	//brickDrawing = brickDrawingBase.get();  // No need to dynamic_cast


	//if (!brickSize)
	//{
	//	std::cout << "NO paddle size component" << std::endl;
	//	return;
	//}

	//if (!brickPosition)
	//{
	//	std::cout << "NO paddle position component" << std::endl;
	//	return;
	//}


	//if (!brickDrawing)
	//{
	//	std::cout << "NO paddle drawable component" << std::endl;
	//	return;
	//}

	//isDrawn = true;

	//brickDrawing->isDrawn = true;

	brickRect.setSize((sf::Vector2f(BRICK_WIDTH, BRICK_HEIGHT)));
	brickRect.setFillColor(sf::Color::Green);
	isDrawn = true;


}
void Brick::Grid(std::vector<Brick>& brickArray)
{
	//for (int x = 0; x < BRICKS_ROW; x++)
	//{
	//	for (int y = 0; y < BRICKS_COL; y++)
	//	{
	//		// Create brick at position (x, y) with offset
	//		Brick brick(x * BRICK_OFFSET_X + BRICK_GRID_OFFSET, y * BRICK_OFFSET_Y + BRICK_PADDING);

	//		// Optionally, you can use SetPosition to adjust the brick position if needed
	//		brick.SetPosition(x * BRICK_OFFSET_X + BRICK_GRID_OFFSET, y * BRICK_OFFSET_Y + BRICK_PADDING);

	//		// Add the brick to the vector
	//		ballArray.emplace_back(std::move(brick));
	//	}
	//}

	for (int row = 0; row < BRICKS_ROW; ++row)  // Loop over rows
	{
		for (int col = 0; col < BRICKS_COL; ++col)  // Loop over columns
		{
			// Calculate the position based on the row and column
			float xPos = col * (BRICK_WIDTH + BRICK_OFFSET_X) + BRICK_GRID_OFFSET;
			float yPos = row * (BRICK_HEIGHT + BRICK_OFFSET_Y) + BRICK_PADDING;

			// Create a brick and set its position
			Brick brick(xPos, yPos);

			// Add the brick to the brick array
			brickArray.push_back(std::move(brick));
		}
	}
	
}

void Brick::Update(sf::RenderWindow& window, std::vector<Brick>& ballArray)
{
	if (!isDrawn)  // Only update if drawing is enabled
	{
		return;
	}


	window.draw(brickRect);
}


void Game::Init() 
{


	brick.Grid(brickArray);


	paddle.Init();
	ball.Init();
	brick.Init();
}

void Game::Update(sf::RenderWindow& window, float deltaTime) 
{
	paddle.Update(window, sf::Keyboard::isKeyPressed(sf::Keyboard::D) - sf::Keyboard::isKeyPressed(sf::Keyboard::Q));
	ball.Update(deltaTime, paddle, window);

	for (auto& brick : brickArray)
	{
		brick.Update(window, brickArray); // Draw each brick
	}
}