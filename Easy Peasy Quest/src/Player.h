#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "SFML/Graphics.hpp"

class Player : public Entity {
private:
	sf::CircleShape* circleShape;
public:
	float x;
	float y;
	float speed;

	Player(float x, float y);
	~Player();

	void update(double delta);
	void render(sf::RenderTarget& renderTarget, double delta);

	void move(float x, float y);
};

#endif // !PLAYER_H