#include "PlayerCamera.h"

PlayerCamera::PlayerCamera(Player* player, sf::RenderWindow* window, sf::View* view)
{
	this->player = player;
	this->window = window;
	this->view = view;
}

PlayerCamera::~PlayerCamera()
{
	this->player = nullptr;
	this->window = nullptr;
	this->view = nullptr;
}

void PlayerCamera::update(double delta)
{
	this->view->setCenter(this->player->x + 320, this->player->y + 240);
	this->window->setView(*this->view);
}

void PlayerCamera::render(sf::RenderTarget& renderTarget, double delta)
{
	// we are not rendering this
}
