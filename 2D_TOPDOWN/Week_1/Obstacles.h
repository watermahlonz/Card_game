#pragma once
#include "SFML\Graphics.hpp"
class Obstacles
{
private:
	sf::RectangleShape obstacles;
	float obstX;
	float obstY;
	float obstHeight;
	float obstWidth;
	bool isObstacle;


public:
	Obstacles(sf::Vector2f objPosition, sf::Vector2f objSize, bool canPass);
	~Obstacles();
	float getObstX();
	float getObstY();
	float getObstWidth();
	float getObstHeight();
	bool canPassThrough();
	sf::RectangleShape getShape();
	void ObstRender(sf::RenderWindow* window);
};

