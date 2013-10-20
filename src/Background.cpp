#include "Background.h"

Background::Background()
{
    sf::Vector2u size = Game::getInstance().getWindow()->getSize();
    background.setTexture(*Game::getInstance().getTexture("background"));
    width  = (*Game::getInstance().getTexture("background")).getSize().x;
    height = (*Game::getInstance().getTexture("background")).getSize().y;
    background.setTextureRect(sf::IntRect(0, 0, size.x + width, size.y + height));
}

Background::~Background()
{
}

void Background::onTick(int millis)
{
    x -= 0.06 * millis;
    if (x < -(float) width) x += width;
}

void Background::draw()
{
    background.setPosition(sf::Vector2f(x, y));
    Game::getInstance().getWindow()->draw(background);
}
