#include "Game.h"
#include "gamestate.h"

Game::Game(const std::string & name)
	:name(name)
{
	state = std::make_unique<NotBoughtGameState>();
}

Game::~Game()
{
}

void Game::buy()
{
	state->buy(this);
}

void Game::install()
{
	state->install(this);
}

void Game::start()
{
	state->start(this);
}

void Game::stop()
{
	state->stop(this);
}

void Game::update()
{
	state->update(this);
}

void Game::uninstall()
{
	state->uninstall(this);
}