#pragma once
#include "Object.h"
#include <iostream>
class Player : public Object
{
public:
	Player();
	Player(std::string pathName, sf::Vector2f Position);
	void ObjUpdate();
	void objSword(float maxSwordDistance);
	void bulletLeft();
	void bulletRight();
	void bulletUp();
	void bulletDown();
	sf::RectangleShape getShape();
	sf::Sprite& getSprite();
	void render(sf::RenderWindow* window);

private:
	sf::Texture playerText;
	sf::Sprite playerSpr;
};

