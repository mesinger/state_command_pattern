#pragma once

#include "commands.hpp"
#include <vector>
#include <memory>

class Menu;
class MenuItem;

class Menu {

private:

	std::vector<std::string> games;

public:

	Menu();
	virtual ~Menu() = default;

	void buyGame(User* user, const std::string& gamename);
	void installGame(Game* pgame);
	void updateGame(Game* pgame);
	void startGame(Game* pgame);
	void stopGame(Game* pgame);
	void uninstallGame(Game* pgame);
	void oneclickplay(Game* pgame);
};

class MenuItem {

private:

	std::shared_ptr<CommandComponent> command;

public:
;
	explicit MenuItem(std::shared_ptr<CommandComponent> command) :command(command){}
	virtual ~MenuItem() = default;

	inline void clicked() {
		command->exec();
	}
};
