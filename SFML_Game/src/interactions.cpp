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

void handleCollisions(ball &ball, brick &brick)
{
    if(!isInteracting(brick, ball))
        return;

    brick.destroy();

    float leftOverlap = ball.right() - brick.left();
    float rightOverlap = brick.right() - ball.left();
    float topOverlap = ball.bottom() - brick.top();
    float bottomOverlap = brick.bottom() - ball.top();

    bool fromLeft = std::abs(leftOverlap) < std::abs(rightOverlap);
    bool fromTop = std::abs(topOverlap) < std::abs(bottomOverlap);

    float minXOverlap = fromLeft ? leftOverlap : rightOverlap;
    float minYOverlap = fromTop ? topOverlap : bottomOverlap;

    if(std::abs(minXOverlap) < std::abs(minYOverlap))
    {
        if(fromLeft)
            ball.moveLeft();
        else
            ball.moveRight();
    }
    else 
    {
        if(fromTop)
            ball.moveUp();
        else
            ball.moveDown();
    }
}
