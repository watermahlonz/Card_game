#include "Enemy.h"

Enemy::Enemy(std::string pathName, sf::Vector2f pos)
{
	m_enemyPos = pos;
	m_enemyTexture.loadFromFile(pathName);
	m_enemySpr.setTexture(m_enemyTexture);

	m_enemySpr.setPosition(m_enemyPos);
}

Enemy::~Enemy()
{

}

void Enemy::render(sf::RenderWindow* window)
{
	window->draw(m_enemySpr);
}

void Enemy::update(sf::Vector2f playerPos, std::vector<Obstacles*> vect)
{


	if (m_enemySpr.getPosition().x == playerPos.x
		&& m_enemySpr.getPosition().y <= playerPos.y)
	{
		if (checkDownCollision(m_enemySpr, vect))
		{

		}
		else
		{
			m_enemySpr.move(0, 1);
		}
	}

	else if (m_enemySpr.getPosition().x == playerPos.x
		&& m_enemySpr.getPosition().y >= playerPos.y)
	{
		if (checkUpCollision(m_enemySpr, vect))
		{

		}
		else
		{
			m_enemySpr.move(0, -1);
		}
	}



	else if (m_enemySpr.getPosition().x <= playerPos.x
		&& m_enemySpr.getPosition().y == playerPos.y)
	{
		if (checkRightCollision(m_enemySpr, vect))
		{

		}
		else
		{
			m_enemySpr.move(1, 0);
		}
	}


	 
	else if (m_enemySpr.getPosition().x >= playerPos.x
		&& m_enemySpr.getPosition().y == playerPos.y)
	{
		if (checkLeftCollision(m_enemySpr, vect))
		{

		}
		else
		{
			m_enemySpr.move(-1, 0);
		}
	}		 

	else if (m_enemySpr.getPosition().x <= playerPos.x
	&& m_enemySpr.getPosition().y <= playerPos.y)
{

		if (checkRightCollision(m_enemySpr, vect) || checkDownCollision(m_enemySpr, vect))
		{

		}
		else
		{
			m_enemySpr.move(1, 1);
		}
}

	else if (m_enemySpr.getPosition().x >= playerPos.x
	&& m_enemySpr.getPosition().y <= playerPos.y)
{
		if (checkLeftCollision(m_enemySpr, vect) || checkDownCollision(m_enemySpr, vect))
		{

		}
		else
		{
			m_enemySpr.move(-1, 1);
		}
}

	else if (m_enemySpr.getPosition().x >= playerPos.x
		&& m_enemySpr.getPosition().y >= playerPos.y)
	{
		if (checkLeftCollision(m_enemySpr, vect) || checkUpCollision(m_enemySpr, vect))
		{

		}
		else
		{
			m_enemySpr.move(-1, -1);
		}
	}	

	else if (m_enemySpr.getPosition().x <= playerPos.x
	&& m_enemySpr.getPosition().y >= playerPos.y)
{
		if (checkRightCollision(m_enemySpr, vect) || checkUpCollision(m_enemySpr, vect))
		{

		}
		else
		{
			m_enemySpr.move(1, -1);
		}
}	
	 
}

bool Enemy::checkLeftCollision(sf::Sprite& player, std::vector<Obstacles*> vect)
{
	for (int i = 0; i < vect.size(); i++)
	{
		if (player.getGlobalBounds().left == vect[i]->getObstX() + vect[i]->getObstWidth() &&
			player.getGlobalBounds().top < vect[i]->getObstY() + vect[i]->getObstHeight() &&
			player.getGlobalBounds().top + player.getGlobalBounds().height > vect[i]->getObstY())
		{
			if (!vect[i]->canPassThrough())
				return true;
		}
	}

	return false;
}

bool Enemy::checkUpCollision(sf::Sprite& player, std::vector<Obstacles*> vect)
{
	for (int i = 0; i < vect.size(); i++)
	{
		if (player.getGlobalBounds().left < vect[i]->getObstX() + vect[i]->getObstWidth() &&
			player.getGlobalBounds().left + player.getGlobalBounds().width > vect[i]->getObstX() &&
			player.getGlobalBounds().top == vect[i]->getObstY() + vect[i]->getObstHeight() &&
			!vect[i]->canPassThrough())
		{

			return true;
		}
	}

	return false;
}

bool Enemy::checkDownCollision(sf::Sprite& player, std::vector<Obstacles*> vect)
{
	for (int i = 0; i < vect.size(); i++)
	{
		if (player.getGlobalBounds().left < vect[i]->getObstX() + vect[i]->getObstWidth() &&
			player.getGlobalBounds().left + player.getGlobalBounds().width > vect[i]->getObstX() &&
			player.getGlobalBounds().top + player.getGlobalBounds().height == vect[i]->getObstY()
			&&
			!vect[i]->canPassThrough())
		{
			return true;
		}
	}

	return false;
}

bool Enemy::checkRightCollision(sf::Sprite& player, std::vector<Obstacles*> vect)
{
	for (int i = 0; i < vect.size(); i++)
	{
		if (player.getGlobalBounds().left + player.getGlobalBounds().width == vect[i]->getObstX() &&
			player.getGlobalBounds().top < vect[i]->getObstY() + vect[i]->getObstHeight() &&
			player.getGlobalBounds().top + player.getGlobalBounds().height > vect[i]->getObstY() &&
			!vect[i]->canPassThrough())
		{
			return true;
		}
	}

	return false;
}

sf::Sprite Enemy::getSprite()
{
	return m_enemySpr;
}
