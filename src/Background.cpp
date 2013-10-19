#include "Background.h"

Background::Background()
{
    rect.setFillColor(sf::Color::White);
    rect.setSize(sf::Vector2f(200, 300));
}

Background::~Background()
{
}

void Background::draw()
{
    rect.setPosition(sf::Vector2f(x, y));
    Game::getInstance().getWindow()->draw(rect);
}
