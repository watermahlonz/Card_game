#pragma once
#include <SFML/Graphics.hpp>

class Object
{
private:
	sf::Vector2f m_objPos;
	std::string m_objPathName;

public:
	Object(std::string pathName, sf::Vector2f position);
	Object();
	~Object();
};

