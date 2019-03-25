#pragma once

#include "commands.hpp"
#include <vector>
#include <memory>

class Menu;
class MenuItem;

class Menu {

private:

	std::unique_ptr<MenuItem> buyMenu;
	std::vector<std::string> games;

public:

	Menu();
	virtual ~Menu() = default;

	void buyGame(User* user, std::string gamename);
};

class MenuItem {

private:

	std::shared_ptr<ICommand> command;

public:
;
	explicit MenuItem(std::shared_ptr<ICommand> command) :command(command){}
	virtual ~MenuItem() = default;

	inline void clicked() {
		command->exec();
	}
};
