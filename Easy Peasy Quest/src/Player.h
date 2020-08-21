#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "SFML/Graphics.hpp"

class Player : public Entity {
private:
	sf::CircleShape* circleShape;
public:
	float speed;

	Player();
	~Player();

	void update(double delta);
	void render(sf::RenderTarget& renderTarget, double delta);

	void move(float x, float y);
};

#endif // !PLAYER_H