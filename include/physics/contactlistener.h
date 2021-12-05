#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

#include "external/box2d/include/box2d/box2d.h"
#include "../engine/gameobject.h"

namespace DT
{
    class ContactListener : public b2ContactListener
    {
    private: 
        void BeginContact(b2Contact* contact);

        void EndContact(b2Contact* contact);
    };
}

#endif