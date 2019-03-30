#pragma once

#include <map>
#include "Game.hpp"

class User {

public:

	const uint64_t id;
	
private:

	std::map<std::string, std::unique_ptr<Game>> library;

public:

	explicit User(uint64_t id) :id(id) {};
	virtual ~User() = default;

	void addGame(const std::string& gamename);
	void removeGame(const std::string& gamename);
	Game* getGame(const std::string& gamename) const;
};
