#pragma once

#include <map>
#include "Game.hpp"

class User {

public:

	const uint64_t id;
	
private:

	std::map<std::string, Game> ownedGames;

public:

	explicit User(uint64_t id) :id(id) {};
	virtual ~User() = default;

	void addGame(std::string gamename);
};
