#include "gamestate.hpp"
#include <iostream>

void BoughtGameState::buy(Game* const pgame)
{
	std::cout << "already bought game" << std::endl;
}

void BoughtGameState::install(Game* const pgame)
{
	std::cout << "installing game" << std::endl;
	pgame->state.reset(new InstalledGameState());
}

void BoughtGameState::start(Game* const pgame)
{
	std::cout << "you need to install the game first" << std::endl;
}

void BoughtGameState::stop(Game * const pgame)
{
	std::cout << "you need to install the game first" << std::endl;
}

void BoughtGameState::update(Game* const pgame)
{
	std::cout << "you need to install the game first" << std::endl;
}

void BoughtGameState::uninstall(Game* const pgame)
{
	std::cout << "game is not installed" << std::endl;
}

void InstalledGameState::buy(Game* const pgame)
{
	std::cout << "already bought game" << std::endl;
}

void InstalledGameState::install(Game* const pgame)
{
	std::cout << "already installed game" << std::endl;
}

void InstalledGameState::start(Game* const pgame)
{
	std::cout << "starting" << std::endl;
	pgame->state.reset(new RunningGameState());
}

void InstalledGameState::stop(Game * const pgame)
{
	std::cout << "game not running" << std::endl;
}

void InstalledGameState::update(Game* const pgame)
{
	std::cout << "updating game" << std::endl;
}

void InstalledGameState::uninstall(Game* const pgame)
{
	std::cout << "uninstalling game" << std::endl;
	pgame->state.reset(new BoughtGameState());
}

void NotBoughtGameState::buy(Game* const pgame)
{
	std::cout << "buying game" << std::endl;
	pgame->state.reset(new BoughtGameState());
}

void NotBoughtGameState::install(Game* const pgame)
{
	std::cout << "you need to buy the game first" << std::endl;
}

void NotBoughtGameState::start(Game* const pgame)
{
	std::cout << "you need to buy the game first" << std::endl;
}

void NotBoughtGameState::stop(Game * const pgame)
{
	std::cout << "you need to buy the game first" << std::endl;
}

void NotBoughtGameState::update(Game* const pgame)
{
	std::cout << "you need to buy the game first" << std::endl;
}

void NotBoughtGameState::uninstall(Game* const pgame)
{
	std::cout << "you need to buy the game first" << std::endl;
}

void RunningGameState::buy(Game* const pgame)
{
	std::cout << "already bought game" << std::endl;
}

void RunningGameState::install(Game* const pgame)
{
	std::cout << "already installed game" << std::endl;
}

void RunningGameState::start(Game* const pgame)
{
	std::cout << "game already started" << std::endl;
}

void RunningGameState::stop(Game * const pgame)
{
	std::cout << "game stoped" << std::endl;
	pgame->state.reset(new InstalledGameState());
}

void RunningGameState::update(Game* const pgame)
{
	std::cout << "can't update while game is running" << std::endl;
}

void RunningGameState::uninstall(Game* const pgame)
{
	std::cout << "can't uninstall while game is running" << std::endl;
}
