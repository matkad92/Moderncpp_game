#pragma once
#include "movingEntity.h"
#include "constants.h"

class ball :
    public movingEntity
{
    static sf::Texture texture;

public:
    ball(float x, float y);

    void update() override;
    void draw(sf::RenderWindow& window) override;

};

