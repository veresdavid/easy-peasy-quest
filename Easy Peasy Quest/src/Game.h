#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "GameConfiguration.h"
#include "Entity.h"

#include <vector>

class Game {
private:
	bool isRunning;
	sf::Clock* clock;
	sf::RenderWindow* window;
	GameConfiguration* gameConfiguration;
	std::vector<Entity*> entities;
public:
	Game(GameConfiguration* gameConfiguration);

	void init();
	void destroy();
	void run();
	void handleInput();
	void update(double delta);
	void render(sf::RenderTarget &renderTarget, double delta);
};

#endif