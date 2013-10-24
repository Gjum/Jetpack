#include "Game.h"

#include <iostream>

Game::Game()
{
    window = NULL;
    player = NULL;
    background = NULL;

    textures.insert(std::pair<std::string, sf::Texture *>("background", new sf::Texture));
    textures.at("background")->setRepeated(true);
    if (!textures.at("background")->loadFromFile("img/background.png"))
    {
        std::cerr << "Error while loading texture 'background'";
    }

    entities.push_back(new Brick); // TODO
}

Game::~Game()
{
}

Game &Game::getInstance()
{
    static Game instance;
    return instance;
}

void Game::init(sf::RenderWindow *windowArg)
{
    window = windowArg;
    restart();
}

void Game::restart()
{
    for (unsigned int a = 0; a < entities.size() - 1; a++)
    {
        Entity *entity = getEntity(a);
        if (entity != NULL) delete(entity);
    }
    entities.clear();

    entities.push_back(background = new Background);
    entities.push_back(player = new Player);
    entities.push_back(new Brick);

    timeSinceLastBrick = 0;
}

void Game::onTick(int millis)
{
    // create new brick
    timeSinceLastBrick += millis;
    if (timeSinceLastBrick > 500)
    {
        timeSinceLastBrick -= 500;
        // TODO debug
//        entities.push_back((Entity *) new Brick);
//        entities.insert(entities.begin(), (Entity *) new Brick);
    }

    for (unsigned int a = 0; a < entities.size() - 1; a++)
    {
        getEntity(a)->onTick(millis);
    }
//    deleteDeadEntities();

    // test for collisions
    for (unsigned int a = 0; a < entities.size() - 1; a++)
    {
        for (unsigned int b = a + 1; b < entities.size(); b++)
        {
            Entity *entA = getEntity(a);
            Entity *entB = getEntity(b);

            std::cout << "Colliding " << entA << " + " << entB << "\n"; // TODO debug

            // Is one of them already dead?
            if (entA->isDead() || entB->isDead()) continue;

            if (intersects(entA, entB))
            {
                entB->onCollide(entA);
                entA->onCollide(entB);
            }
        }
    }
//    deleteDeadEntities();
}

void Game::deleteDeadEntities()
{
    for (unsigned int a = 0; a < entities.size() - 1; a++)
    {
        Entity *entity = getEntity(a);
        if (entity->isDead())
        {
            std::cout << "Erasing " << entity << "\n";

            if (entity != NULL) delete entity;
            else std::cerr << "Error while deleting NULL entity pointer\n";

            entities.erase(entities.begin() + a);
        }
    }
}

bool Game::intersects(Entity *a, Entity *b)
{
    sf::IntRect rectA = a->getRect();
    sf::IntRect rectB = b->getRect();
    return rectA.intersects(rectB);
}

void Game::draw()
{
    if (window == NULL)
    {
        std::cerr << "Error while drawing to uninitialized window pointer";
        return;
    }

    background->draw();

    for (unsigned int a = 0; a < entities.size() - 1; a++)
    {
        Entity *entity = getEntity(a);
        if (entity == background) continue;
        if (entity == player) continue;

        entity->draw();
    }
    player->draw();
}

sf::RenderWindow *Game::getWindow()
{
    return window;
}

sf::Texture *Game::getTexture(std::string name)
{
    return textures.at(name);
}

Entity *Game::getEntity(unsigned int id)
{
    return entities.at(id);
}

#undef FOR_EACH_VEC
