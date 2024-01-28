#pragma once

#include "entity.h"
#include "constants.h"

class brick : public entity
{
    static sf::Texture texture;

public:

    brick(float x, float y);

    void update() override;
    void draw(sf::RenderWindow& window) override;
};

