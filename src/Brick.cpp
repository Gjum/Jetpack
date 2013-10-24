#include "Brick.h"

Brick::Brick()
{
    width = 64;
    height = 64;

    x = Game::getInstance().getWindow()->getSize().x + width;
    y = Game::getInstance().getWindow()->getSize().y / 2;

    // pixels per second
    xSpeed = -0.5;
    ySpeed = 0.0;

    rect.setOrigin(sf::Vector2f(width / 2, height / 2));
    rect.setSize(sf::Vector2f(width, height));
    rect.setFillColor(sf::Color::Red);
}

Brick::~Brick()
{
}

CollisionType Brick::getCollisionType()
{
    return CollisionType::BRICK;
}

void Brick::onTick(int millis)
{
    x += xSpeed * millis;
    y += ySpeed * millis;

    if (x < -(float) width) die();
}

void Brick::draw()
{
    rect.setPosition(
        sf::Vector2f(x, Game::getInstance().getWindow()->getSize().y - y));
    Game::getInstance().getWindow()->draw(rect);
}
