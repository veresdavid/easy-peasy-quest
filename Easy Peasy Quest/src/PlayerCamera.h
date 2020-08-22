#ifndef PLAYER_CAMERA_H
#define PLAYER_CAMERA_H

#include "Entity.h"
#include "Player.h"

class PlayerCamera : public Entity {
private:
	Player* player;
	sf::RenderWindow* window;
	sf::View* view;
public:
	PlayerCamera(Player* player, sf::RenderWindow* window, sf::View* view);
	~PlayerCamera();

	void update(double delta);
	void render(sf::RenderTarget& renderTarget, double delta);
};

#endif // !PLAYER_CAMERA_H