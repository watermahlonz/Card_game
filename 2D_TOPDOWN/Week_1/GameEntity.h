#pragma once
#include "SFML\Graphics.hpp"
class GameEntity
{
private:
	sf::RectangleShape shape;
	sf::Vector2f Position;
	sf::Vector2f Scale;
	std::vector<GameEntity*> children;

public:
	GameEntity();
	~GameEntity();
	sf::RectangleShape getShape();
	void addChild(GameEntity* child);

	void update();
	void render(sf::RenderWindow* window);

};

