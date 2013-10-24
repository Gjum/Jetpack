#ifndef PLAYER_H
#define PLAYER_H

#include "Colliding.h"
#include "Ball.h"
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
        void CollisionBorder ();
        void die();

    private:
        float ySpeed, yVelocity;
        sf::RectangleShape rect;
};

#endif // PLAYER_H
