#pragma once
#include "entity.h"
class movingEntity :
    public entity
{
protected:
    //sfml vector store object velocity(distance ball moves between screen updates)
    sf::Vector2f velocity;

public:

};

