#include "Game.h"
#include "DummyEntity.h"
#include <memory>

Game::Game(GameConfiguration* gameConfiguration)
{
	this->gameConfiguration = gameConfiguration;
}

void Game::init()
{
	this->window = new sf::RenderWindow(sf::VideoMode(gameConfiguration->windowWidth, gameConfiguration->windowHeight), gameConfiguration->windowTitle);
	this->clock = new sf::Clock();

	// TODO: only for testing, remove it later!
	DummyEntity* entityOne = new DummyEntity("Entity #1");
	DummyEntity* entityTwo = new DummyEntity("Entity #2");
	this->entities.push_back(entityOne);
	this->entities.push_back(entityTwo);
}

void Game::destroy()
{
	delete window;
	this->window = nullptr;

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
