#pragma once
#include <SFML/Graphics.hpp>

//abstract class representing graphic entity
class entity {
protected:
	sf::Sprite sprite;
public:
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

	//virtual functions must be implemented in inheriting classes
	//virtual destructor to be sure, destructor will be called using polimorphism

	virtual ~entity() {}
};