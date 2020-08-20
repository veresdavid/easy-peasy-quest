#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>

#include "GameConfiguration.h"
#include "Game.h"

bool isRunning = true;
sf::CircleShape shape(100.f);
int circleSpeed = 100;

void handleInput(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            isRunning = false;
            window.close();
        }
    }
}

void update(double delta) {
    if (shape.getPosition().x > 640 - 200) {
        shape.setPosition(640 - 200, 0);
        circleSpeed *= -1;
    }
    else if (shape.getPosition().x < 0) {
        shape.setPosition(0, 0);
        circleSpeed *= -1;
    }

    shape.move(circleSpeed * delta / 1000000.0, 0);
}

void render(sf::RenderWindow &window, double delta) {
    window.clear();
    window.draw(shape);
    window.display();
}

std::string generateWindowTitle(int fps, int ups) {
    std::stringstream ss;
    ss << "Easy Peasy Quest | FPS: " << fps << " , UPS: " << ups;
    return ss.str();
}

class Base {
public:
    virtual void dummy() = 0;
};

class Foo : public Base {
public:
    void dummy() override {
        std::cout << "Dummy" << std::endl;
    }
};

int main()
{
    /*
    sf::RenderWindow window(sf::VideoMode(640, 480), "Easy Peasy Quest");
    shape.setFillColor(sf::Color::Green);

    // clock
    // we are working with microseconds!
    const int MAX_UPDATES_PER_SECOND = 60;
    const int MAX_FRAMES_PER_SECOND = 60;

    const double UPDATE_TIME = 1000000 / MAX_UPDATES_PER_SECOND;
    const double FRAME_TIME = 1000000 / MAX_FRAMES_PER_SECOND;

    double updateDeltaTime = 0.0;
    double frameDeltaTime = 0.0;

    sf::Clock clock;

    // statistics
    int updates = 0;
    int frames = 0;
    double statisticsTimer = 0.0;

    // game loop
    while (isRunning) {
        // time handling
        int delta = clock.getElapsedTime().asMicroseconds();
        updateDeltaTime += delta;
        frameDeltaTime += delta;
        statisticsTimer += delta;
        clock.restart();

        // handle input
        handleInput(window);

        // update
        while (updateDeltaTime >= UPDATE_TIME) {
            update(updateDeltaTime);
            updateDeltaTime -= UPDATE_TIME;
            updates++;
        }

        // render
        if (frameDeltaTime >= FRAME_TIME) {
            render(window, frameDeltaTime);
            frameDeltaTime -= FRAME_TIME;
            frames++;
        }

        // statistics
        if (statisticsTimer >= 1000000) {
            window.setTitle(generateWindowTitle(frames, updates));
            statisticsTimer = 0.0;
            updates = 0;
            frames = 0;
        }

        // sleep till next update
        sf::sleep(sf::microseconds(UPDATE_TIME) - sf::microseconds(updateDeltaTime));
    }
    */

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