#ifndef DUMMY_ENTITY_H
#define DUMMY_ENTITY_H

#include "Entity.h"

class DummyEntity : public Entity {
private:
	std::string name;
	double threshold;
public:
	DummyEntity(std::string name);

	void update(double delta);
	void render(sf::RenderTarget& renderTarget, double delta);
};

#endif