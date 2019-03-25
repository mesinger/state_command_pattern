#include "User.hpp"

void User::addGame(std::string gamename)
{
	Game game(gamename);
	game.buy();

	ownedGames.emplace(gamename, game);
}
