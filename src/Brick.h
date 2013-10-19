#ifndef BRICK_H
#define BRICK_H

#include "Colliding.h"
#include "Game.h"

#include <SFML/Graphics.hpp>

class Brick : public Colliding
{
    public:
        Brick();
        ~Brick();

        void onTick(int millis);
        void draw();

    private:
        float xSpeed, ySpeed;
        sf::RectangleShape rect;
};

#endif // BRICK_H
