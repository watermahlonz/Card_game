#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cards.h"
#include "Button.h"
#include "Game.h"

// the abstract base class
class Node
{
public:

    // ... functions to transform the node
    Node()
    {

    }

    void setTransform(sf::Transform transform)
    {
        m_transform = transform;
    }

    sf::Transform getTransform()
    {
        return m_transform;
    }

    // ... functions to manage the node's children
    void addChild(Node* child)
    {
        m_children.push_back(child);
    }

    void draw(sf::RenderTarget& target, const sf::Transform& parentTransform) const
    {
        // combine the parent transform with the node's one
        sf::Transform combinedTransform = parentTransform * m_transform;

        // let the node draw itself
        onDraw(target, combinedTransform);

        // draw its children
        for (std::size_t i = 0; i < m_children.size(); ++i)
        {
            m_children[i]->draw(target, combinedTransform);
        }

    }

private:

    virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const = 0;

    sf::Transform m_transform;
    std::vector<Node*> m_children;
};

// a simple derived class: a node that draws a sprite
class SpriteNode : public Node
{
public:
    // .. functions to define the sprite
    SpriteNode(sf::Transform transform)
    {
        setTransform(transform);
        m_sprite.setFillColor(sf::Color::Red);
        m_sprite.setSize(sf::Vector2f(10.f, 10.f));
    }

private:

    virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const
    {
        target.draw(m_sprite, transform);
    }

    sf::RectangleShape m_sprite;
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
    sf::Clock clock;
    //sf::Vector2f velocity(0.0f, 0.0f);
    //sf::Vector2f accelaration(0.0f, 3.0f);
    int playersTurn = 1;
    //sf::Transform t;
    //t.translate(sf::Vector2f(5, 5));
    //sf::Transform a;
    //t.translate(sf::Vector2f(50, 50));
    //sf::Transform s;
    //t.translate(sf::Vector2f(20, 20));

    Button increasePillz("Increase", sf::Vector2f(250.f, 50.f));
    Button decreasePillz("Decrease", sf::Vector2f(50.f, 50.f));
    Button closeButton("Close", sf::Vector2f(50.f, 250.f));
    Button fightButton("Fight", sf::Vector2f(250.f, 250.f));

    //SpriteNode* sp = nullptr;
    //sp = new SpriteNode(t);
    //SpriteNode som(a);
    //SpriteNode tim(s);

    //tim.setTransform(a);
    //som.setTransform(s);

    //sp->addChild(&som);
    //sp->addChild(&tim);


    Cards exampleCard(3, 5, "Leeroy", sf::Vector2f(100, 100), sf::Color::Red);
    Cards exampleCard2(6, 5, "Anduin", sf::Vector2f(400, 400), sf::Color::Blue);
    Cards* selectedP1 = nullptr;
    Cards* selectedP2 = nullptr;
    //sf::Font gameFont;
    //sf::Text gameText;
    //gameFont.loadFromFile("space.ttf");
    //gameText.setFont(gameFont);

    //sf::Vector2f mouse;

    int player1Health1 = 12;
    int player1Health2 = 12;

    int player1Pillz = 12;
    int player2Pillz = 12;

    int player1SelectedPillz = 0;
    int player2SelectedPillz = 0;

    bool displayPillzUI = false;
    bool player1Ready = false;
    bool player2Ready = false;

    sf::Clock glock;
    float timer = 0.0f;

    float deltaTime;
    std::cout << "Players 1 turn!!!: " << std::endl;
    std::cout << "Player1Health: " << player1Health1 << "--- Player2Health: " << player1Health2 << std::endl;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (playersTurn == 1)
                {
                    if (exampleCard.getShape().getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window)))
                    {
                        selectedP1 = &exampleCard;
                        selectedP1->setOutlineColor(sf::Color::White);

                        displayPillzUI = true;




                    }

                    if (displayPillzUI == true)
                    {
                        if (decreasePillz.getShape().getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window)))
                        {
                            if(player1SelectedPillz > 0)
                            player1SelectedPillz--;

                            std::cout << player1SelectedPillz << std::endl;
                        }

                        if (increasePillz.getShape().getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window)))
                        {
                            if (player1SelectedPillz < player1Pillz)
                                player1SelectedPillz++;

                            std::cout << player1SelectedPillz << std::endl;
                        }

                        if (closeButton.getShape().getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window)))
                        {
                            displayPillzUI = false;
                            selectedP1 = nullptr;
                        }

                        if (fightButton.getShape().getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window)))
                        {
                            displayPillzUI = false;
                            player1Ready = true;
                            player1Pillz -= player1SelectedPillz;
                        }
                    }

                    if (player1Ready)
                    {
                        playersTurn = 2;
                        std::cout << "Players 2 turn!!!: " << std::endl;
                    }
                }

                else if (playersTurn == 2)
                {
                    if (exampleCard2.getShape().getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window)))
                    {
                        selectedP2 = &exampleCard2;
                        selectedP2->setOutlineColor(sf::Color::White);
                    }
                }
            }

            //if (event.type == sf::Event::KeyPressed)
            //{
            //}
        }


        if (selectedP1 != nullptr && selectedP2 != nullptr)
        {
            timer += glock.restart().asSeconds();

            if (timer >= 3)
            {
                if (selectedP1->getAttack() * player1SelectedPillz > selectedP2->getAttack())
                {
                    player1Health2 -= selectedP1->getDamage();
                }

                else if (selectedP1->getAttack() < selectedP2->getAttack())
                {
                    player1Health1 -= selectedP2->getDamage();
                }

                else
                {
                    std::cout << "TIE" << std::endl;
                }

                selectedP1->setOutlineColor(sf::Color::Red);
                selectedP2->setOutlineColor(sf::Color::Blue);

                selectedP1 = nullptr;
                selectedP2 = nullptr;
                player1Ready = false;
                player2Ready = false;

                std::cout << "Player1Health: " << player1Health1 << "--- Player2Health: " << player1Health2 << std::endl;
                std::cout << "Player1Pillz: " << player1Pillz << "--- Player2Pillz: " << player2Pillz << std::endl;
                std::cout << "Players 1 turn!!!: " << std::endl;

                playersTurn = 1;

                timer = 0.0f;
            }

            std::cout << playersTurn << std::endl;


        }

        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        //{
        //    velocity.y = -10;
        //}

        //shape.setPosition(shape.getPosition() + velocity * deltaTime * 10.0f);
        //velocity = velocity + accelaration * deltaTime;

        window.clear(sf::Color::Green);
        //window.draw(shape);
        exampleCard.render(&window);
        exampleCard2.render(&window);

        if (displayPillzUI)
        {
            closeButton.render(&window);
            fightButton.render(&window);
            increasePillz.render(&window);
            decreasePillz.render(&window);
        }
        //sp->draw(window, a);

        window.display();
    }

    //
    //Game game;
    //game.run();

    return 0;
}