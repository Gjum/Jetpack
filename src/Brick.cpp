#include "Brick.h"

Brick::Brick()
{
    // pixels per second
    xSpeed = -0.5;
    ySpeed = 0.0;

    width = 64;
    height = 64;

    x = Game::getInstance().getWindow()->getSize().x + width;

    srand (time(0));
    y =  (rand () % Game::getInstance().getWindow()->getSize().y);                                                          //Game::getInstance().getWindow()->getSize().y / 2;


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

    // TODO die if out of sight
    if (x < -(float) width) x = 500;
}

void Brick::draw()
{
    rect.setPosition(
        sf::Vector2f(x, Game::getInstance().getWindow()->getSize().y - y));
    Game::getInstance().getWindow()->draw(rect);
}

//void Brick::onCollide(Colliding *colliding)
//{
//    if (colliding->getCollisionType() == CollisionType::PLAYER)
//        ((Player *) colliding)->die();
//}
