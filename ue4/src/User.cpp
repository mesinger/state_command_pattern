#include "User.hpp"

void User::addGame(std::string gamename)
{
	Game game(gamename);
	game.buy();

	ownedGames.emplace(gamename, game);
}

Game * User::getGame(std::string gamename)
{
	//Game& ref = ownedGames.at(gamename);
	//Game* res = &ref;
	return &ownedGames.at(gamename);
}
