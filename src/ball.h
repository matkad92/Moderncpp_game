#pragma once
#include "movingEntity.h"
#include "constants.h"

class ball : public movingEntity
{
    static sf::Texture texture;

public:
    ball(float x, float y);

    void update() override;
    void draw(sf::RenderWindow& window) override;

    virtual void moveUp() noexcept override;
	virtual void moveLeft() noexcept override;
	virtual void moveRight() noexcept override;

};

