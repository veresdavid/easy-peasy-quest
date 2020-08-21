#include "Player.h"

Player::Player()
{
	this->speed = 300;
	this->circleShape = new sf::CircleShape(50);
	this->circleShape->setFillColor(sf::Color(0, 255, 0));
}

Player::~Player()
{
	delete this->circleShape;
	this->circleShape = nullptr;
}

void Player::update(double delta)
{
}

void Player::render(sf::RenderTarget& renderTarget, double delta)
{
	renderTarget.draw(*this->circleShape);
}

void Player::move(float x, float y)
{
	this->circleShape->move(x, y);
}
