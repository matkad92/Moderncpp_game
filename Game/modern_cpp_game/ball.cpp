#include "ball.h"


sf::Texture ball::texture;//initializing data

ball::ball(float x, float y): movingEntity()  //initialization list
{
	//Loading texture
	texture.loadFromFile("img/ball.png");

	sprite.setTexture(texture);

	sprite.setPosition(x, y);
	velocity = { constants::ballSpeed, constants::ballSpeed}; //6 is set, meaning ball will move 6pix right and down
}

void ball::update()
{
	sprite.move(velocity);
}

void ball::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
