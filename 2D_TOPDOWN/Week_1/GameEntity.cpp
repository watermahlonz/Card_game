#include "GameEntity.h"

GameEntity::GameEntity()
{
	Position = { 10, 10 };
	Scale = { 75, 125 };
	shape.setPosition(Position);
	shape.setSize(Scale);
	shape.setFillColor(sf::Color::Red);
}

GameEntity::~GameEntity()
{

}

sf::RectangleShape GameEntity::getShape()
{
	return shape;
}

void GameEntity::addChild(GameEntity* child)
{
	children.push_back(child);
}

void GameEntity::update()
{
	for (GameEntity* child : children)
	{
		child->update();
	}
}

void GameEntity::render(sf::RenderWindow* window)
{
	for (GameEntity* child : children)
	{
		child->render(window);
	}
}
