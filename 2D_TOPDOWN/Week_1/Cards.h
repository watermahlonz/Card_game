#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Cards
{
private:
	int cardAttack;
	int cardDamage;
	std::string cardName;
	sf::RectangleShape card;

public:
	Cards(int attack, int damage, std::string name, sf::Vector2f pos, sf::Color col);
	int getAttack();
	int getDamage();
	std::string getName();
	void render(sf::RenderWindow* window);
	void setPos(sf::Vector2f mousePos);
	void setColor(sf::Color col);
	void setOutlineColor(sf::Color outline);
	sf::RectangleShape getShape();
};

