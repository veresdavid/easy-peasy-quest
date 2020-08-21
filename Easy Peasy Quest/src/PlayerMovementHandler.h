#ifndef PLAYER_MOVEMENT_HANDLER_H
#define PLAYER_MOVEMENT_HANDLER_H

#include "Entity.h"
#include "Player.h"

class PlayerMovementHandler : public Entity {
private:
	Player* player;
public:
	PlayerMovementHandler(Player* player);
	~PlayerMovementHandler();

	void update(double delta);
	void render(sf::RenderTarget& renderTarget, double delta);
};

#endif // !PLAYER_MOVEMENT_HANDLER_H