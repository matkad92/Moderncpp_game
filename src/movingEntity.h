#pragma once
#include "entity.h"
class movingEntity :  public entity
{
protected:
    sf::Vector2f velocity;

public:

    virtual void moveUp() noexcept = 0;
	virtual void moveLeft() noexcept = 0;
	virtual void moveRight() noexcept = 0;

};

