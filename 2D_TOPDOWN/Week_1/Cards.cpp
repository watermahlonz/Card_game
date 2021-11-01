#include "Cards.h"

Cards::Cards(int attack, int damage, std::string name, sf::Vector2f pos, sf::Color color)
{
	cardAttack = attack;
	cardDamage = damage;
	cardName = name;

	card.setPosition(pos);
	card.setFillColor(color);
	card.setOutlineThickness(5.0f);
	card.setOutlineColor(color);
	card.setSize(sf::Vector2f(75, 125));
}

int Cards::getAttack()
{
	return cardAttack;
}

int Cards::getDamage()
{
	return cardDamage;
}

std::string Cards::getName()
{
	return cardName;
}

void Cards::render(sf::RenderWindow* window)
{
	window->draw(card);
}

void Cards::setPos(sf::Vector2f mousePos)
{
	card.setPosition(mousePos);
}

void Cards::setColor(sf::Color col)
{
	card.setFillColor(col);
}

void Cards::setOutlineColor(sf::Color outline)
{
	card.setOutlineColor(outline);
}

sf::RectangleShape Cards::getShape()
{
	return card;
}
