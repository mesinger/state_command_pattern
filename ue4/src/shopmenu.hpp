#pragma once

#include "commands.hpp"
#include <vector>
#include <memory>

class Menu;
class MenuItem;

class Menu {

private:

	std::vector<std::string> games;
	std::vector<std::string> borrowedGamesLog;

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
	void borrow(User* owner, User* receiver, Game* game);
	void returnGameByOwner(User* owner, User* receiver, Game* game);
	void returnGameByReceiver(User* owner, User* receiver, Game* game);
	void removeGame(User* user, const std::string& gamename) const;

	void addBorrowedGameToDataBase(User* owner, User* receiver, const std::string& gamename);
	void removeBorrowedGameFromDataBase(User* owner, User* receiver, const std::string& gamename);
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
