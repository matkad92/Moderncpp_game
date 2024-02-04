#pragma once
#include "movingEntity.h"
#include "constants.h"


class paddle : public movingEntity
{
	static sf::Texture texture;
	
	void processPlayerInput();

public:
	paddle(float x, float y);

	void update() override;
	void draw(sf::RenderWindow& window) override;

	virtual void moveUp() noexcept override;
	virtual void moveDown() noexcept override;
	virtual void moveLeft() noexcept override;
	virtual void moveRight() noexcept override;
};

