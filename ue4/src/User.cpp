#include "User.hpp"

void User::addGame(const std::string& gamename)
{
	std::unique_ptr<Game> game = std::make_unique<Game>(gamename);
	game->buy();

	library.emplace(gamename, std::move(game));
}

void User::removeGame(const std::string & gamename)
{
	library.erase(gamename);
}

Game * User::getGame(const std::string& gamename) const
{
	return library.at(gamename).get();
}
