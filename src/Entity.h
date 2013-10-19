#ifndef ENTITY_H
#define ENTITY_H

//#include "Jetpack.h"

class Entity
{
    public:
        Entity();
        virtual ~Entity();

        virtual void draw();

    protected:
        int x, y;
        unsigned int width, height;

};

#endif // ENTITY_H
