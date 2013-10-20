#include "Game.h"

//#include <iostream>

#define FOR_EACH_VEC(element, vector) for(auto element = vector.begin(); element != vector.end(); element++)

Game::Game()
{
    window = NULL;
    player = NULL;
    background = NULL;

    textures.insert(std::pair<std::string, sf::Texture *>("background", new sf::Texture));
    textures.at("background")->setRepeated(true);
    if (!textures.at("background")->loadFromFile("background.png"))
    {
        // TODO error: texture not loaded
    }

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
    restart();
}

void Game::restart()
{
    FOR_EACH_VEC(entity, entities)
    {
        if ((*entity) != NULL) delete(*entity);
    }
    entities.erase(entities.begin(), entities.end());

    entities.push_back(background = new Background);
    entities.push_back(new Brick);
    entities.push_back(player = new Player);
}

void Game::onTick(int millis)
{
    FOR_EACH_VEC(entity, entities)
    {
        (*entity)->onTick(millis);
    }

    for (unsigned int a = 0; a < getEntityAmount() - 1; a++)
    {
        for (unsigned int b = a + 1; b < getEntityAmount(); b++)
        {
            Colliding *entA = dynamic_cast<Colliding *>(getEntity(a));
            Colliding *entB = dynamic_cast<Colliding *>(getEntity(b));

            // are we dealing with two Colliding objects?
            if (entA == NULL || entB == NULL) continue;

            if (intersects(entA, entB))
            {
                entA->onCollide(entB);
                entB->onCollide(entA);
            }
        }
    }

    deleteDeadEntities();
}

void Game::draw()
{
    if (window == NULL)
    {
        // TODO error: window not initialized
        return;
    }

    background->draw();
    FOR_EACH_VEC(entity, entities)
    {
        if ((*entity) == background) continue;
        if ((*entity) == player) continue;

        (*entity)->draw();
    }
    player->draw();
}

sf::Texture *Game::getTexture(std::string name)
{
    return textures.at(name);
}

unsigned int Game::getEntityAmount()
{
    return entities.size();
}

Entity *Game::getEntity(unsigned int id)
{
    return entities.at(id);
}

void Game::deleteDeadEntities()
{
    // TODO deleteDeadEntities
}

bool Game::intersects(Entity *a, Entity *b)
{
    sf::IntRect rectA = a->getRect();
    sf::IntRect rectB = b->getRect();
    return rectA.intersects(rectB);
}

#undef FOR_EACH_VEC
