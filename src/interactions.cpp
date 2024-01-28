#include "interactions.h"

bool isInteracting(const entity &e1, const entity &e2)
{
    
    auto box1 =e1.get_bounding_box();
    auto box2 =e2.get_bounding_box();

    return box1.intersects(box2);
}

void handleCollisions(ball &b, const paddle &p)
{
    if(isInteracting(p,b))
    {
        b.moveUp();

        if(b.x()<p.x())
            b.moveLeft();
        else
            b.moveRight();
    }
}
