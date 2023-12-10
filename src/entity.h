#pragma once
#include <SFML/Graphics.hpp>

//abstract class representing graphic entity
class entity {
protected:
	sf::Sprite sprite;
public:
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

	//Bounding box getter:
	sf::FloatRect get_bounding_box() const noexcept;

	//Getting centre of the spirit:
	sf::Vector2f get_centre() const noexcept;

	//Getting positions of the spirit:
	float x() const noexcept;
	float y() const noexcept;

	//virtual functions must be implemented in inheriting classes
	//virtual destructor to be sure, destructor will be called using polimorphism

	virtual ~entity() {}
};