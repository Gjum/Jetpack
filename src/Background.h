#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Entity.h"
#include "Game.h"

#include <SFML/Graphics.hpp>

class Background : public Entity
{
    public:
        Background();
        ~Background();

        void onTick(int millis);
        void draw();

    private:
        sf::Sprite background;
};

#endif // BACKGROUND_H
