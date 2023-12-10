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
	if (x() < 0) velocity.x = -velocity.x;
	if (y() < 0) velocity.y = -velocity.y;
	if (x() > constants::window_width) velocity.x = -velocity.x;
	if (y() > constants::window_height) velocity.y = -velocity.y;

}

void ball::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
