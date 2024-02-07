#include "brick.h"

sf::Texture brick::texture;

const sf::Color brickColorHit1{0, 255, 0, 80};
const sf::Color brickColorHit2{0, 255, 0, 170};
const sf::Color brickColorHit3{0, 255, 0, 255};


brick::brick(float x, float y): entity() 
{
    texture.loadFromFile("img/brick01.png");
    sprite.setTexture(texture);

    sprite.setPosition(x,y);
    sprite.setOrigin(get_centre());

    destroyed = false;
}

void brick::setStrenght(int s) noexcept
{
    strenght = s;
}

void brick::weaken() noexcept
{
    --strenght;
}

bool brick::isTooWeak() const noexcept
{
    return strenght <= 0;
}

void brick::update()
{
    if(strenght == 1)
        sprite.setColor(brickColorHit1);
    if(strenght == 2)
        sprite.setColor(brickColorHit2);
    if(strenght == 3)
        sprite.setColor(brickColorHit3);
}

void brick::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}
