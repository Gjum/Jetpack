#ifndef ENTITY_H
#define ENTITY_H

//enum EntityType
//{
//    Background,
//    Player,
//    Wall,
//    Brick,
//    Rocket,
//    Ball
//}

class Entity
{
    public:
        Entity();
        virtual ~Entity();

        virtual void setPosition(int xArg, int yArg);
        virtual void move(int xArg, int yArg);

        virtual void onTick(int millis);
        virtual void draw();

    protected:
        float x, y;
        unsigned int width, height;

};

#endif // ENTITY_H
