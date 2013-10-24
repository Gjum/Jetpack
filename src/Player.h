#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Ball.h"
#include "Game.h"

#include <SFML/Graphics.hpp>

class Player : public Entity
{
    public:
        Player();
        ~Player();

        CollisionType getCollisionType();

        void onTick(int millis);
        void draw();
        void onCollide(Entity *entity);

        void die();

    private:
        float xSpeed, ySpeed,
              xVelocity, yVelocity, gravity,
              maxXSpeed, maxYSpeed;
        sf::RectangleShape rect;
};

#endif // PLAYER_H
