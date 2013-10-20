#ifndef COLLIDING_H
#define COLLIDING_H

#include "Entity.h"

enum CollisionType
{
    BRICK,
    PLAYER,
    BALL,
    NONE
};

class Colliding : public Entity
{
    public:
        Colliding();
        virtual ~Colliding();

        virtual CollisionType getCollisionType();

        virtual void onTick(int millis);
        virtual void onCollide(Colliding *colliding);

    protected:
};

#endif // COLLIDING_H
