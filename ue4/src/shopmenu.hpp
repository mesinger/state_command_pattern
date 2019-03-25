#pragma once

#include "commands.hpp"
#include <vector>
#include <memory>

class Menu;
class MenuItem;

class Menu {

private:

	std::vector<std::string> games;

	User* const user;

public:

	Menu(User* user);
	virtual ~Menu() = default;

	void buyGame(std::string gamename);
	void installGame(Game* pgame);
	void updateGame(Game* pgame);
	void startGame(Game* pgame);
	void stopGame(Game* pgame);
	void uninstallGame(Game* pgame);
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
