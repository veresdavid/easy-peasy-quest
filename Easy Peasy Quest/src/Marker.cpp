#include "Marker.h"

Marker::Marker(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	this->rectangleShape = new sf::RectangleShape(sf::Vector2f(width, height));
	this->rectangleShape->setPosition(sf::Vector2f(x, y));
	this->rectangleShape->setFillColor(sf::Color(255, 255, 255));
}

Marker::~Marker()
{
	delete this->rectangleShape;
	this->rectangleShape = nullptr;
}

void Marker::update(double delta)
{
	// nothing
}

void Marker::render(sf::RenderTarget& renderTarget, double delta)
{
	renderTarget.draw(*this->rectangleShape);
}
