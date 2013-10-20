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

// has to be called by ancestors: Colliding::onTick(millis);
void Colliding::onTick(int millis)
{
    // TODO test for collision
//    for ()
//    {
//        if (true)
//        {
//            onCollide
//        }
//    }
}

void Colliding::onCollide(Colliding *colliding)
{
}
