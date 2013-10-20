#include "Entity.h"

Entity::Entity()
{
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    dead = false;
}

Entity::~Entity()
{
}

void Entity::setPosition(int xArg, int yArg)
{
    x = xArg;
    y = yArg;
}

void Entity::move(int xArg, int yArg)
{
    x += xArg;
    y += yArg;
}

void Entity::onTick(int millis)
{
}

void Entity::draw()
{
}

void Entity::die()
{
    dead = true;
}

bool Entity::isDead()
{
    return dead;
}

sf::IntRect Entity::getRect()
{
    return sf::IntRect(x - width / 2, y - height / 2, width, height);
}
