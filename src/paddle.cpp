#include "paddle.h"

sf::Texture paddle::texture;

void paddle::processPlayerInput()
{
	//left key, chcecking if paddle do not move out of the screen
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		if (x() >= 0) velocity.x = -constants::paddleSpeed;
		else velocity.x = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		if (x() <= constants::window_width) velocity.x = constants::paddleSpeed;
		else velocity.x = 0;
	}
	else velocity.x = 0;
}

paddle::paddle(float x, float y) : movingEntity()  //initialization list
{
	texture.loadFromFile("img/paddle.png");

	sprite.setTexture(texture);

	sprite.setPosition(x, y);
	velocity = { 0.0f, 0.0f};

	sprite.setOrigin(get_centre());//setting sprite origin to center not top left corner
}

void paddle::update()
{
	sprite.move(velocity);
	processPlayerInput();
}

void paddle::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void paddle::moveUp() noexcept
{}

void paddle::moveDown() noexcept
{}

void paddle::moveLeft() noexcept
{
	velocity.y = -constants::ballSpeed;
}

void paddle::moveRight() noexcept 
{ 
	velocity.y = constants::ballSpeed;
}