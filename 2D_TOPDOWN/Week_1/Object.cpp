#include "Object.h"

Object::Object(std::string pathName, sf::Vector2f position)
{
	m_objPathName = pathName;
	m_objPos = position;
}

Object::Object()
{

}

Object::~Object()
{

}
