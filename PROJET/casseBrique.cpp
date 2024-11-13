#include "casseBrique.h"

void Paddle::Draw(sf::RenderWindow& window)
{
	Component* paddleSizeBase = paddleComponent.GetComponent<Size>("Size");
	Size* paddleSize = dynamic_cast<Size*>(paddleSizeBase);

	if (paddleSize) 
	{
		float paddleWidth = paddleSize->width;
		float paddleHeight = paddleSize->height;

		sf::RectangleShape paddle(sf::Vector2f(paddleWidth, paddleHeight));

		window.draw(paddle);
	}
	Component* paddlePositionBase = paddleComponent.GetComponent<Position>("Position");
	Position* paddlePosition = dynamic_cast<Position*>(paddlePositionBase);

	//paddle.setFillColor(sf::Color::Blue);

	if (paddlePosition) 
	{
		float paddleX = paddlePosition->x;
		float paddleY = paddlePosition->y;

		//paddle
	}

}
