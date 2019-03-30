#pragma once

#include "User.hpp"
#include "Game.hpp"
#include "composite.hpp"

class Menu;

class BuyCommand : public CommandComposite{

private:

	User* const receiver;
	const std::string gamename;

public:

	BuyCommand(User* const receiver, const std::string& game) :receiver(receiver), gamename(game){}
	virtual ~BuyCommand() = default;

	virtual void exec() override;
};

class InstallCommand : public CommandComposite {

private:

	Game* const game;

public:

	InstallCommand(Game* game) :game(game) {}
	virtual ~InstallCommand() = default;

	virtual void exec() override;
};

class StartCommand : public CommandComposite {

private:

	Game* const game;

public:

	StartCommand(Game* game) :game(game) {}
	virtual ~StartCommand() = default;

	virtual void exec() override;
};

class StopCommand : public CommandComposite {

private:

	Game* const game;

public:

	StopCommand(Game* game) :game(game) {}
	virtual ~StopCommand() = default;

	virtual void exec() override;
};

class UpdateCommand : public CommandComposite {

private:

	Game* const game;

public:

	UpdateCommand(Game* game) :game(game) {}
	virtual ~UpdateCommand() = default;

	virtual void exec() override;
};

class UninstallCommand : public CommandComposite {

private:

	Game* const game;

public:

	UninstallCommand(Game* game) :game(game) {}
	virtual ~UninstallCommand() = default;

	virtual void exec() override;
};

class BorrowCommand : public CommandComposite {

private:

	Game* const game;

public:

	BorrowCommand(Game* game) :game(game) {}
	virtual ~BorrowCommand() = default;

	virtual void exec() override;
};

class ReturnGameCommand : public CommandComposite {

private:

	Game* const game;

public:

	ReturnGameCommand(Game* game) :game(game) {}
	virtual ~ReturnGameCommand() = default;

	virtual void exec() override;
};

class OneClickPlayCommand : public CommandComposite {

private:

	Game* const game;

public:

	OneClickPlayCommand(Game* game);
	virtual ~OneClickPlayCommand() = default;
};

class BorrowGameToUserCommand : public CommandComposite {

private:

	Game* const game;
	User* const owner;
	User* const receiver;
	Menu* const shop;

public:

	BorrowGameToUserCommand(User* owner, User* receiver, Game* game, Menu* shop);
	virtual ~BorrowGameToUserCommand() = default;
};

class BorrowGameShopCommands : public CommandComposite {

private:

	Game* const game;
	User* const owner;
	User* const receiver;
	Menu* const shop;

public:

	BorrowGameShopCommands(User* owner, User* receiver, Game* game, Menu* shop);
	virtual ~BorrowGameShopCommands() = default;
};

class BorrorwGameShopStorageCommand : public CommandComposite {

private:

	std::string gamename;
	User* const owner;
	User* const receiver;
	Menu* const shop;

public:

	BorrorwGameShopStorageCommand(User* owner, User* receiver, const std::string& gamename, Menu* shop);

	virtual ~BorrorwGameShopStorageCommand() = default;

	virtual void exec() override;
};

class ReturnGameShopStorageCommand : public CommandComposite {

private:

	std::string gamename;
	User* const owner;
	User* const receiver;
	Menu* const shop;

public:

	ReturnGameShopStorageCommand(User* owner, User* receiver, const std::string& gamename, Menu* shop);

	virtual ~ReturnGameShopStorageCommand() = default;

	virtual void exec() override;
};

class ReturnGameByOwnerCommand : public CommandComposite {

private:

	std::string gamename;
	User* const owner;
	User* const receiver;
	Menu* const shop;

public:

	ReturnGameByOwnerCommand(User* owner, User* receiver, const std::string& gamename, Menu* shop);

	virtual ~ReturnGameByOwnerCommand() = default;
};

class ReturnGameByReceiverCommand : public CommandComposite {

private:

	std::string gamename;
	User* const owner;
	User* const receiver;
	Menu* const shop;

public:

	ReturnGameByReceiverCommand(User* owner, User* receiver, const std::string& gamename, Menu* shop);

	virtual ~ReturnGameByReceiverCommand() = default;
};

class RemoveGameCommand : public CommandComposite {

private:

	Menu* const shop;
	User* const user;
	std::string gamename;

public:

	RemoveGameCommand(Menu* shop, User* user, const std::string& gamename) :shop(shop), user(user), gamename(gamename) {}

	virtual ~RemoveGameCommand() = default;

	virtual void exec() override;
};
