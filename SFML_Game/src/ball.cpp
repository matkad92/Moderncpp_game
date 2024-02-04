#include "ball.h"


sf::Texture ball::texture;

ball::ball(float x, float y): movingEntity()  
{
	texture.loadFromFile("img/ball.png");

	sprite.setTexture(texture);

	sprite.setPosition(x, y);
	velocity = { constants::ballSpeed, constants::ballSpeed}; //6 is set
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

void ball::moveUp() noexcept
{
	velocity.y = -constants::ballSpeed;
}

void ball::moveDown() noexcept
{
	velocity.y = constants::ballSpeed;
}

void ball::moveLeft() noexcept
{
	velocity.x = -constants::ballSpeed;
}

void ball::moveRight() noexcept 
{ 
	velocity.x = constants::ballSpeed;
}

