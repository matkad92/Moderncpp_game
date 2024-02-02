#pragma once
#include <SFML/Graphics.hpp>

class entity {
protected:

	sf::Sprite sprite;
	bool destroyed{false}; //nie dziala inicjalizacja w ten sposob 
	
public:

	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

	float x() const noexcept;//box center
	float y() const noexcept;

	sf::FloatRect get_bounding_box() const noexcept;
	sf::Vector2f get_centre() const noexcept;

	float left() const noexcept;
	float right() const noexcept;
	float top() const noexcept;
	float bottom() const noexcept;

	void destroy() noexcept;
	bool is_destroyed() const noexcept;


	virtual ~entity() {}
};