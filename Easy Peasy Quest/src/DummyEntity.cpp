#include "DummyEntity.h"
#include <iostream>

DummyEntity::DummyEntity(std::string name)
{
	this->name = name;
	this->threshold = 0.0;
}

void DummyEntity::update(double delta)
{
	this->threshold += delta;

	if (threshold >= 1000000) {
		threshold = 0.0;
		std::cout << "Hello, I am" << name << std::endl;
	}
}

void DummyEntity::render(sf::RenderTarget& renderTarget, double delta)
{
}
