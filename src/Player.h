#ifndef PLAYER_H
#define PLAYER_H

#include "Colliding.h"
#include "Game.h"

#include <SFML/Graphics.hpp>

class Player : public Colliding
{
    public:
        Player();
        ~Player();

        CollisionType getCollisionType();

        void onTick(int millis);
        void draw();
        void onCollide(Colliding *colliding);

        void die();

    private:
        float xSpeed, ySpeed,
            xVelocity, yVelocity, gravity,
            maxXSpeed, maxYSpeed;
        sf::RectangleShape rect;
};

#endif // PLAYER_H
