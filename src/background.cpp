#include "background.h"

sf::Texture background::texture;

background::background(float x, float y){
	texture.loadFromFile("img/background.jpg");
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}

void background::update() {

}

void background::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}
