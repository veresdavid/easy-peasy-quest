#ifndef GAME_CONFIGURATION_H
#define GAME_CONFIGURATION_H

#include <iostream>

class GameConfiguration {
public:
	// update related configuration
	int maxUpdatesPerSecond;
	int maxFramesPerSecond;
	double updateTime;
	double frameTime;

	// window related configuration
	std::string windowTitle;
	int windowWidth;
	int windowHeight;
};

#endif // !GAME_CONFIGURATION_H