#include "Button.h"

Button::Button(std::string text, sf::Vector2f pos)
{
	if (!button_font.loadFromFile("space.ttf"))
	{
		std::cout << "Error cannot load font!!!" << std::endl;
	}

	//number = &data;

	button_text.setFont(button_font);
	button_text.setCharacterSize(24);
	button_text.setString(text);
	button_text.setFillColor(sf::Color::White);

	box.setPosition(pos);
	box.setSize(sf::Vector2f(90.f, 25.f));
	box.setFillColor(sf::Color::Magenta);

	button_text.setPosition(pos);
}

Button::Button()
{

}

sf::RectangleShape Button::getShape()
{
	return box;
}

void Button::update()
{
	//*number--;
}

void Button::render(sf::RenderWindow* window)
{
	window->draw(box);
	window->draw(button_text);
}
