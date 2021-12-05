#include "polygoncollider.h"
using namespace DT;

void PolygonCollider2D::Start()
{
    rb = gameObject->GetComponent<Rigidbody2D>();
    if(rb == nullptr)
    {
        Debug::LogError("The GameObject needs a Rigidbody component to be able to attach a Collider.");
        return;
    }

    b2PolygonShape collisionShape;

    int size = points.size();

    if(size < 3 || size > 8)
    {
        Debug::LogError("The number of vertices in a polygonCollider must be >= 3 and <= 8, the number of vertices chosen is " + std::to_string(size));
        return;
    }

    b2Vec2 vertices[size];
    for(int i=0,n=size;i<n;i++)
    {
        vertices[i].Set(points[i].x, points[i].y);
    }
    collisionShape.Set(vertices, size);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &collisionShape;
    fixtureDef.density = density;
    fixtureDef.friction = friction;
    fixtureDef.isSensor = isTrigger;

    rb->body->CreateFixture(&fixtureDef);
}