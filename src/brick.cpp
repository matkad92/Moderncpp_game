#include "brick.h"

sf::Texture brick::texture;

brick::brick(float x, float y): entity() 
{
    texture.loadFromFile("img/brick01.png");
    sprite.setTexture(texture);

    sprite.setPosition(x,y);
    sprite.setOrigin(get_centre());

    destroyed = false;
}

void brick::update()
{
    
}

void brick::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}
