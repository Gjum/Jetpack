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

        void onTick(int millis);
        void draw();

    private:
        float xSpeed, ySpeed,
            xVelocity, yVelocity, gravity,
            maxXSpeed, maxYSpeed;
        sf::RectangleShape rect;
};

#endif // PLAYER_H
