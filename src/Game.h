#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>

class Entity;
class Background;
class Player;
class Brick;

class Game
{
    public:
        static Game &getInstance();
        sf::RenderWindow *getWindow();

        void init(sf::RenderWindow *windowArg);
        void onTick(int millis);
        void draw();

    private:
        Game();
        Game(Game const &);
        ~Game();
        Game &operator=(Game const &);

        sf::RenderWindow *window;

        Background *background;
        Player *player;
        std::vector<Brick *> bricks;
};

#include "Background.h"
#include "Player.h"
#include "Brick.h"
#include "Entity.h"

#endif // GAME_H
