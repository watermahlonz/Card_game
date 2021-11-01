#include "Player.h"

Player::Player()
{

}

Player::Player(std::string pathName, sf::Vector2f Position) :
	Object(pathName, Position)
{
	//playerText = new sf::Texture;
	playerText.loadFromFile(pathName);

	//playerSpr = new sf::Sprite;
	playerSpr.setTexture(playerText);

	playerSpr.setPosition(Position);
}

void Player::ObjUpdate()
{
	playerSpr.move(10, 0);
}

void Player::objSword(float maxSwordDistance)
{
	float attackDistance = maxSwordDistance - 40.f;
	std::cout << maxSwordDistance << std::endl;

	if (playerSpr.getPosition().y > attackDistance)
	{
		playerSpr.move(0, -10);
	}

	else if(playerSpr.getPosition().y < attackDistance)
	{
		playerSpr.move(0, 10);
	}
}

void Player::bulletLeft()
{
	playerSpr.move(-10, 0);
}

void Player::bulletRight()
{

}

void Player::bulletUp()
{
	playerSpr.move(0, -10);
}

void Player::bulletDown()
{
	playerSpr.move(0, 10);
}

sf::RectangleShape Player::getShape()
{
	return sf::RectangleShape();
}

sf::Sprite& Player::getSprite()
{
	return playerSpr;
}

void Player::render(sf::RenderWindow* window)
{
	window->draw(playerSpr);
}
