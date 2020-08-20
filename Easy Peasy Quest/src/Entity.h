#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
public:
	virtual void update(double delta) = 0;
	virtual void render(sf::RenderTarget &renderTarget, double delta) = 0;
};

#endif