#pragma once
#include "movingEntity.h"
#include "constants.h"


class paddle : public movingEntity
{
	static sf::Texture texture;

public:
	paddle(float x, float y);

	void update() override;
	void draw(sf::RenderWindow& window) override;
};

