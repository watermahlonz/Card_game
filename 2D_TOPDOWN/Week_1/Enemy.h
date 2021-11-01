#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Obstacles.h"
class Enemy
{
public:
	Enemy(std::string pathName, sf::Vector2f pos);
	~Enemy();
	void render(sf::RenderWindow* window);
	void update(sf::Vector2f playerPos, std::vector<Obstacles*> vect);
	bool checkLeftCollision(sf::Sprite& player, std::vector<Obstacles*> vect);
	bool checkUpCollision(sf::Sprite& player, std::vector<Obstacles*> vect);
	bool checkDownCollision(sf::Sprite& player, std::vector<Obstacles*> vect);
	bool checkRightCollision(sf::Sprite& player, std::vector<Obstacles*> vect);
	sf::Sprite getSprite();

private:
	sf::Sprite m_enemySpr;
	sf::Texture m_enemyTexture;
	sf::Vector2f m_enemyPos;
};

