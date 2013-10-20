#include "Colliding.h"

Colliding::Colliding()
{
}

Colliding::~Colliding()
{
}

CollisionType Colliding::getCollisionType()
{
    return CollisionType::NONE;
}

void Colliding::onTick(int millis)
{
}

void Colliding::onCollide(Colliding *colliding)
{
}
