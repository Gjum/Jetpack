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
    yVelocity = 0.009;
    gravity   = 0.004;

    x = 50;
    y = Game::getInstance().getWindow()->getSize().y / 2;

    width = 32;
    height = 32;

    rect.setOrigin(sf::Vector2f(width / 2, height / 2));
    rect.setSize(sf::Vector2f(width, height));
    rect.setFillColor(sf::Color::Blue);
}

Player::~Player()
{
}

CollisionType Player::getCollisionType()
{
    return CollisionType::PLAYER;
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
    const float friction = 0.3;
    xSpeed -= friction * xSpeed * xSpeed * (xSpeed > 0 ? 1 : -1);
    ySpeed -= friction * ySpeed * ySpeed * (ySpeed > 0 ? 1 : -1);

    x += xSpeed * millis;
    y += ySpeed * millis;

    Colliding::onTick(millis);
}

void Player::draw()
{
    rect.setPosition(sf::Vector2f(x, Game::getInstance().getWindow()->getSize().y - y));
    Game::getInstance().getWindow()->draw(rect);
}

void Player::die()
{
    Game::getInstance().restart();
}

void Player::onCollide(Colliding *colliding)
{
    CollisionType type = colliding->getCollisionType();
    if (type == CollisionType::BRICK)
        die();
    else if (type == CollisionType::BALL)
    {
        // TODO apply effect of the ball

        // TODO destroy the ball
        colliding->die();
    }
}
