#include "GameConfiguration.h"
#include "Game.h"

int main()
{
    GameConfiguration* gameConfiguration = new GameConfiguration();
    gameConfiguration->maxUpdatesPerSecond = 60;
    gameConfiguration->maxFramesPerSecond = 60;
    gameConfiguration->updateTime = 1000000.0 / 60.0;
    gameConfiguration->frameTime = 1000000.0 / 60.0;
    gameConfiguration->windowWidth = 640;
    gameConfiguration->windowHeight = 480;
    gameConfiguration->windowTitle = "Easy Peasy Quest";

    Game* game = new Game(gameConfiguration);
    game->init();
    game->run();
    game->destroy();

    delete game;
    game = nullptr;
    delete gameConfiguration;
    gameConfiguration = nullptr;

    return 0;
}