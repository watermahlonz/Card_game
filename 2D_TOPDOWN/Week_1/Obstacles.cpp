#include "Obstacles.h"

Obstacles::Obstacles(sf::Vector2f objPosition, sf::Vector2f objSize, bool canPass)
{
	isObstacle = canPass;
	obstacles.setPosition(objPosition);
	obstacles.setSize(objSize);
	obstacles.setOrigin(15, 15);

	obstX = obstacles.getGlobalBounds().left;
	obstY = obstacles.getGlobalBounds().top;
	obstWidth = obstacles.getGlobalBounds().width;
	obstHeight = obstacles.getGlobalBounds().height;

	if (canPass == false)
	{
		obstacles.setFillColor(sf::Color::Red);
	}
	else
	{
		obstacles.setFillColor(sf::Color::Magenta);
	}
	obstacles.setOutlineThickness(5);
	obstacles.setOutlineColor(sf::Color::Yellow);
}

Obstacles::~Obstacles()
{

}

float Obstacles::getObstX()
{
	return obstX;
}

float Obstacles::getObstY()
{
	return obstY;
}

float Obstacles::getObstWidth()
{
	return obstWidth;
}

float Obstacles::getObstHeight()
{
	return obstHeight;
}

bool Obstacles::canPassThrough()
{
	return isObstacle;
}

sf::RectangleShape Obstacles::getShape()
{
	return obstacles;
}

void Obstacles::ObstRender(sf::RenderWindow* window)
{
	window->draw(obstacles);
}
