#include "Entity.h"

Entity::Entity()
{
    x = 0;
    y = 0;
    width = 0;
    height = 0;
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
