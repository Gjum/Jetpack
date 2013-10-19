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

        void draw();

    private:
        sf::RectangleShape rect;
};

#endif // BACKGROUND_H
