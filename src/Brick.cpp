#include "Brick.h"

Brick::Brick()
{
    // pixels per second
    xSpeed = -0.5;
    ySpeed = 0.0;

    x = 500;
    y = Game::getInstance().getWindow()->getSize().y / 2;

    rect.setFillColor(sf::Color::Red);
    rect.setSize(sf::Vector2f(64, 64));
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
}

void Brick::draw()
{
    rect.setPosition(
        sf::Vector2f(x, Game::getInstance().getWindow()->getSize().y - y));
    Game::getInstance().getWindow()->draw(rect);
}
