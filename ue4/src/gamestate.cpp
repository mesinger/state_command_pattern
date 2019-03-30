#include "gamestate.hpp"
#include <iostream>

void BoughtGameState::install(Game* const pgame)
{
	std::cout << "installing game" << std::endl;
	pgame->state.reset(new InstalledGameState());
}

void InstalledGameState::start(Game* const pgame)
{
	std::cout << "starting" << std::endl;
	pgame->state.reset(new RunningGameState());
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

void RunningGameState::stop(Game * const pgame)
{
	std::cout << "game stoped" << std::endl;
	pgame->state.reset(new InstalledGameState());
}

void InstalledGameState::update(Game* const pgame)
{
	std::cout << "updating game" << std::endl;
}

void BoughtGameState::borrow(Game * const pgame)
{
	std::cout << "borrowed game" << std::endl;
	pgame->state.reset(new BorrowedGameState(false));
}

void InstalledGameState::borrow(Game * const pgame) 
{
	std::cout << "borrowed game" << std::endl;
	pgame->state.reset(new BorrowedGameState(true));
}

void BorrowedGameState::returnGame(Game * const pgame)
{
	std::cout << "returned game" << std::endl;

	if (installed) pgame->state.reset(new InstalledGameState());
	else pgame->state.reset(new BoughtGameState());
}

void BorrowedGameState::uninstall(Game * const pgame) 
{
	if (installed) {

		std::cout << "uninstalling game" << std::endl;
		installed = false;
	}
}

void BorrowedGameState::install(Game * const pgame)
{
	if (!installed) {

		std::cout << "installing game" << std::endl;
		installed = true;
	}
}

void BorrowedGameState::update(Game * const pgame)
{
	if (installed) {

		std::cout << "updating game" << std::endl;
	}
}

#pragma region unused

void InstalledGameState::returnGame(Game * const pgame) {}

void BoughtGameState::buy(Game* const pgame) {}

void BoughtGameState::start(Game* const pgame) {}

void BoughtGameState::stop(Game * const pgame) {}

void BoughtGameState::update(Game* const pgame) {}

void BoughtGameState::uninstall(Game* const pgame) {}

void BoughtGameState::returnGame(Game * const pgame) {}

void InstalledGameState::buy(Game* const pgame) {}

void InstalledGameState::install(Game* const pgame) {}

void InstalledGameState::stop(Game * const pgame) {}

void NotBoughtGameState::install(Game* const pgame) {}

void NotBoughtGameState::start(Game* const pgame) {}

void NotBoughtGameState::stop(Game * const pgame) {}

void NotBoughtGameState::update(Game* const pgame) {}

void NotBoughtGameState::uninstall(Game* const pgame) {}

void NotBoughtGameState::borrow(Game * const pgame) {}

void NotBoughtGameState::returnGame(Game * const pgame) {}

void RunningGameState::buy(Game* const pgame) {}

void RunningGameState::install(Game* const pgame) {}

void RunningGameState::start(Game* const pgame) {}

void RunningGameState::update(Game* const pgame) {}

void RunningGameState::uninstall(Game* const pgame) {}

void RunningGameState::borrow(Game * const pgame) {}

void RunningGameState::returnGame(Game * const pgame) {}

void BorrowedGameState::buy(Game * const pgame) {}

void BorrowedGameState::start(Game * const pgame) {}

void BorrowedGameState::stop(Game * const pgame) {}

void BorrowedGameState::borrow(Game * const pgame) {}

#pragma endregion
