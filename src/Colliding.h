#ifndef COLLIDING_H
#define COLLIDING_H

#include "Entity.h"

enum CollisionType
{
    BRICK,
    PLAYER,
    NONE
};

class Colliding : public Entity
{
    public:
        Colliding();
        virtual ~Colliding();

        virtual CollisionType getCollisionType();

        virtual void onTick(int millis); // has to be called by ancestors: Colliding::onTick(millis);
        virtual void onCollide(Colliding *colliding);

    protected:
};

#endif // COLLIDING_H
