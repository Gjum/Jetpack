#include "Game.h"

#define foreachvec(element, vector) for(auto element = vector.begin(); element != vector.end(); element++)

Game::Game()
{
    window = NULL;
    player = NULL;
    background = NULL;
}

Game::~Game()
{
}

Game &Game::getInstance()
{
    static Game instance;
    return instance;
}

sf::RenderWindow *Game::getWindow()
{
    return window;
}

void Game::init(sf::RenderWindow *windowArg)
{
    window = windowArg;

    if (background != NULL) delete background;
    background = new Background;

    if (player != NULL) delete player;
    player = new Player;

    foreachvec(brick, bricks)
    {
        if ((*brick) != NULL) delete (*brick);
    }
    bricks.erase(bricks.begin(), bricks.end());
    bricks.push_back(new Brick);
}

void Game::onTick(int millis)
{
    foreachvec(brick, bricks)
    {
        (*brick)->onTick(millis);
    }

    player->onTick(millis);

    // TODO background movement
}

void Game::draw()
{
    if (window == 0)
    {
        // TODO error
        return;
    }

    background->draw();
    foreachvec(brick, bricks)
        (*brick)->draw();
    player->draw();
}

#undef foreachvec
