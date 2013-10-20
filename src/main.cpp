#include "Game.h"

#include <SFML/Graphics.hpp>

int main(int argc, char *argv[])
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(800, 450), "Game");
    sf::Clock timer;

    Game::getInstance().init(window);

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Return)
                    Game::getInstance().init(window);
                else if (event.key.code == sf::Keyboard::Escape)
                    window->close();
            }
        }

        Game::getInstance().onTick(timer.restart().asMilliseconds());

        window->clear();
        Game::getInstance().draw();
        window->display();
    }

    return EXIT_SUCCESS;
}
