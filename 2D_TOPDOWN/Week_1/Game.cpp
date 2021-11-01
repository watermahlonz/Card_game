#include "Game.h"

void Game::update()
{

}

void Game::render()
{
    window.clear();
    button->render(&window);
    window.display();
}

void Game::run()
{
	while (window.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

Game::Game() : window(sf::VideoMode(800, 800), "Paint App")
{
    pillz = 12;
	button = new Button("close", sf::Vector2f(50.f, 50.f));
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (button->getShape().getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window)))
            {
                //std::cout << "Close button pressed" << std::endl;
                --pillz;
                std::cout << pillz << std::endl;
            }
        }
    }
}

