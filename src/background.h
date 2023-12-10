#pragma once

#include "constants.h"
#include "entity.h"



class background : public entity {
	
	static sf::Texture texture;

public:
	//SFML convention
	//(0,0) top left corner
	//y increase downwards
	//x increase to the right
	background(float x, float y);

	void update() override;
	void draw(sf::RenderWindow& window) override;

};