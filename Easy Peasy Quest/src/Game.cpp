#include "Game.h"
#include "Player.h"
#include "PlayerMovementHandler.h"
#include "PlayerCamera.h"
#include "Marker.h"

Game::Game(GameConfiguration* gameConfiguration)
{
	this->gameConfiguration = gameConfiguration;
}

void Game::init()
{
	this->window = new sf::RenderWindow(sf::VideoMode(gameConfiguration->windowWidth, gameConfiguration->windowHeight), gameConfiguration->windowTitle);
	this->view = new sf::View(sf::FloatRect(0, 0, gameConfiguration->windowWidth, gameConfiguration->windowHeight));
	this->window->setView(*this->view);
	this->clock = new sf::Clock();

	// TODO: only for testing, remove it later!
	// markers for the corners
	Marker* upperLeft = new Marker(0, 0, 100, 100);
	Marker* upperRight = new Marker(540, 0, 100, 100);
	Marker* lowerLeft = new Marker(0, 380, 100, 100);
	Marker* lowerRight = new Marker(540, 380, 100, 100);

	// player
	Player* player = new Player(270, 190);
	this->player = player;
	PlayerMovementHandler* playerMovementHandler = new PlayerMovementHandler(player);
	PlayerCamera* playerCamera = new PlayerCamera(player, this->window, this->view);

	// register entities
	this->entities.push_back(upperLeft);
	this->entities.push_back(upperRight);
	this->entities.push_back(lowerLeft);
	this->entities.push_back(lowerRight);
	this->entities.push_back(player);
	this->entities.push_back(playerMovementHandler);
	this->entities.push_back(playerCamera);
}

void Game::destroy()
{
	delete window;
	this->window = nullptr;

	delete view;
	this->view = nullptr;

	delete clock;
	this->clock = nullptr;

	for (Entity* entity : this->entities) {
		delete entity;
	}
	this->entities.clear();
}

void Game::run()
{
	this->isRunning = true;
	this->clock->restart();

	double updateDeltaTime = 0.0;
	double frameDeltaTime = 0.0;

	while (this->isRunning) {
		// time handling
		int delta = this->clock->getElapsedTime().asMicroseconds();
		this->clock->restart();

		updateDeltaTime += delta;
		frameDeltaTime += delta;

		// input handling
		this->handleInput();

		// update
		while (updateDeltaTime >= gameConfiguration->updateTime) {
			this->update(updateDeltaTime);
			updateDeltaTime -= gameConfiguration->updateTime;
		}

		// render
		if (frameDeltaTime >= gameConfiguration->frameTime) {
			this->render(*this->window, frameDeltaTime);
			frameDeltaTime -= gameConfiguration->frameTime;
		}

		// sleep
		// TODO: maybe this should be refactored!!!
		sf::sleep(sf::microseconds(gameConfiguration->updateTime) - sf::microseconds(updateDeltaTime));
	}
}

void Game::handleInput()
{
	sf::Event event;

	while (this->window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			isRunning = false;
			this->window->close();
		}
	}
}

void Game::update(double delta)
{
	for (Entity* entity : this->entities) {
		entity->update(delta);
	}
}

void Game::render(sf::RenderTarget& renderTarget, double delta)
{
	this->window->clear();

	for (Entity* entity : this->entities) {
		entity->render(*this->window, delta);
	}

	this->window->display();
}
