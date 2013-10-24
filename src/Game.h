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

        void init(sf::RenderWindow *windowArg);
        void restart();
        void onTick(int millis);
        void draw();

        sf::RenderWindow *getWindow();
        sf::Texture *getTexture(std::string name);
        Entity *getEntity(unsigned int id);

    private:
        Game();
        Game(Game const &);
        ~Game();
        Game &operator=(Game const &);

        sf::RenderWindow *window;
        std::map<std::string, sf::Texture *> textures;

        Background *background;
        Player *player;
        std::vector<Entity *> entities;

        unsigned int timeSinceLastBrick;

        bool intersects(Entity *a, Entity *b);
        void deleteDeadEntities();
};

#include "Background.h"
#include "Player.h"
#include "Brick.h"
#include "Entity.h"

#endif // GAME_H
