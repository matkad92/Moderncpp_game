#pragma once

#include "entity.h"
#include "constants.h"

class brick : public entity
{
    static sf::Texture texture;

    int strenght{constants::brickStrenght};

public:

    brick(float x, float y);

    void setStrenght(int) noexcept;
    void weaken() noexcept;
    bool isTooWeak() const noexcept;

    void update() override;
    void draw(sf::RenderWindow& window) override;
};
