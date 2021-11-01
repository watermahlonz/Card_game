#pragma once
#include "SFML\Graphics.hpp"
#include "Button.h"
class Game
{
private:
	Button* button;
	sf::RenderWindow window;
	int pillz;

public:
	Game();
	void run();
	void processEvents();
	void setUp();
	void update();
	void render();
};

