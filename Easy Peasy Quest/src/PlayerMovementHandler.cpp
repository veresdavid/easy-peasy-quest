#include "PlayerMovementHandler.h"

PlayerMovementHandler::PlayerMovementHandler(Player* player)
{
	this->player = player;
}

PlayerMovementHandler::~PlayerMovementHandler()
{
	this->player = nullptr;
}

void PlayerMovementHandler::update(double delta)
{
	float deltaSeconds = delta / 1000000.0;
	sf::Vector2f movementVector(0, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		movementVector += sf::Vector2f(-1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		movementVector += sf::Vector2f(0, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		movementVector += sf::Vector2f(1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		movementVector += sf::Vector2f(0, 1);
	}

	movementVector = movementVector * deltaSeconds * player->speed;

	this->player->move(movementVector.x, movementVector.y);
}

void PlayerMovementHandler::render(sf::RenderTarget& renderTarget, double delta)
{
	// this is not rendered
}
