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
        void restart();
        void onTick(int millis);
        void draw();

        sf::Texture *getTexture(std::string name);
        unsigned int getEntityAmount();
        Entity *getEntity(unsigned int id);
        void deleteDeadEntities();

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

        bool intersects(Entity *a, Entity *b);
};

#include "Background.h"
#include "Player.h"
#include "Brick.h"
#include "Entity.h"

#endif // GAME_H
