#ifndef MARKER_H
#define MARKER_H

#include "Entity.h"
#include "SFML/Graphics.hpp"

class Marker : public Entity {
private:
	float x;
	float y;
	float width;
	float height;
	sf::RectangleShape* rectangleShape;
public:
	Marker(float x, float y, float width, float height);
	~Marker();

	void update(double delta);
	void render(sf::RenderTarget& renderTarget, double delta);
};

#endif // !MARKER_H