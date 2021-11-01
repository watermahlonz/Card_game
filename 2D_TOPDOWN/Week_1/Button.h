#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
class Button
{

private:
	sf::RectangleShape box;
	sf::Font button_font;
	sf::Text button_text;
	int* number;

public:
	Button(std::string text, sf::Vector2f pos);
	Button();
	sf::RectangleShape getShape();
	void update();
	void render(sf::RenderWindow* window);
};

