#ifndef BRICK_H
#define BRICK_H

#include "Entity.h"
#include "Game.h"

#include <SFML/Graphics.hpp>

class Brick : public Entity
{
    public:
        Brick();
        ~Brick();

        CollisionType getCollisionType();

        void onTick(int millis);
        void draw();

    private:
        float xSpeed, ySpeed;
        sf::RectangleShape rect;
};

#endif // BRICK_H
