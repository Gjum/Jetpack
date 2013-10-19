#include "Player.h"

Player::Player()
{
    // pixels per second
    xSpeed = 0.0;
    ySpeed = 0.0;
    maxXSpeed = 0.5;
    maxYSpeed = 0.5;
    // pixels per second per second
    xVelocity = 0.002;
    yVelocity = 0.002;
    gravity   = 0.001;

    x = 50;
    y = Game::getInstance().getWindow()->getSize().y / 2;

    rect.setFillColor(sf::Color::Blue);
    rect.setSize(sf::Vector2f(32, 32));
}

Player::~Player()
{
}

void Player::onTick(int millis)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) xSpeed += xVelocity * millis;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) xSpeed -= xVelocity * millis;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) ySpeed += yVelocity * millis;
    ySpeed -= gravity * millis;

//    if (xSpeed > maxXSpeed)  xSpeed =  maxXSpeed;
//    if (xSpeed < -maxXSpeed) xSpeed = -maxXSpeed;
//    if (ySpeed > maxYSpeed)  ySpeed =  maxYSpeed;
//    if (ySpeed < -maxYSpeed) ySpeed = -maxYSpeed;

    // friction
    xSpeed -= 0.3 * xSpeed * xSpeed * (xSpeed > 0 ? 1 : -1);
    ySpeed -= 0.05 * ySpeed * ySpeed * (ySpeed > 0 ? 1 : -1);

    x += xSpeed * millis;
    y += ySpeed * millis;
}

void Player::draw()
{
    rect.setPosition(sf::Vector2f(x, Game::getInstance().getWindow()->getSize().y - y));
    Game::getInstance().getWindow()->draw(rect);
}
