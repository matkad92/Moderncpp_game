#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include "ball.h"
#include "paddle.h"

bool isInteracting(const entity& e1, const entity& e2);

void handleCollisions(ball& b, const paddle& p);


#endif //INTERACTIONS_H