#include "paddle.h"

sf::Texture paddle::texture;

paddle::paddle(float x, float y) : movingEntity()  //initialization list
{
	//Loading texture
	texture.loadFromFile("img/paddle.png");

	sprite.setTexture(texture);

	sprite.setPosition(x, y);
	velocity = { 0.0f, 0.0f};
}

void paddle::update()
{
	sprite.move(velocity);
}

void paddle::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
