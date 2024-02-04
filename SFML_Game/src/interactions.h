#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include "ball.h"
#include "paddle.h"
#include "brick.h"

bool isInteracting(const entity& e1, const entity& e2);

void handleCollisions(ball& b, const paddle& p);

void handleCollisions(ball& b, brick& p);


#endif //INTERACTIONS_H