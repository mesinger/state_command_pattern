#include "User.hpp"

void User::addGame(const std::string& gamename)
{
	Game game(gamename);
	game.buy();

	ownedGames.emplace(gamename, game);
}

Game * User::getGame(const std::string& gamename)
{
	return &ownedGames.at(gamename);
}
