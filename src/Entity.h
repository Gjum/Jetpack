#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics/Rect.hpp>

enum CollisionType
{
    BRICK,
    PLAYER,
    BALL,
    NONE
};

class Entity
{
    public:
        Entity();
        virtual ~Entity();

        virtual CollisionType getCollisionType();

        virtual void setPosition(int xArg, int yArg);
        virtual void move(int xArg, int yArg);

        virtual void onTick(int millis);
        virtual void onCollide(Entity *entity);
        virtual void draw();
        virtual void die();
        bool isDead();
        sf::IntRect getRect();

    protected:
        float x, y;
        unsigned int width, height;
        bool dead;

};

#endif // ENTITY_H
