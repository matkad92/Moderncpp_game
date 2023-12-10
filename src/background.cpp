#include "background.h"

//Initialize static data member (tape sf Texture , name...)

sf::Texture background::texture;

background::background(float x, float y){
	//Loading texture
	texture.loadFromFile("img/background.jpg");

	sprite.setTexture(texture);

	sprite.setPosition(x, y);
}

//computing new background position
void background::update() {

}

void background::draw(sf::RenderWindow& window) {
	//Window drawing the sprite
	window.draw(sprite);
}
