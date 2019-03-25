#pragma once

#include "User.hpp"
#include "Game.hpp"

class ICommand {

public:

	virtual void exec() = 0;
};

class BuyCommand : public ICommand{

private:

	User* const receiver;
	const std::string gamename;

public:

	BuyCommand(User* const receiver, const std::string& game) :receiver(receiver), gamename(game){}
	virtual ~BuyCommand() = default;

	virtual void exec() override;
};

class InstallCommand : public ICommand {

private:

	Game* const game;

public:

	InstallCommand(Game* game) :game(game) {}
	virtual ~InstallCommand() = default;

	virtual void exec() override;
};

class StartCommand : public ICommand {

private:

	Game* const game;

public:

	StartCommand(Game* game) :game(game) {}
	virtual ~StartCommand() = default;

	virtual void exec() override;
};

class StopCommand : public ICommand {

private:

	Game* const game;

public:

	StopCommand(Game* game) :game(game) {}
	virtual ~StopCommand() = default;

	virtual void exec() override;
};

class UpdateCommand : public ICommand {

private:

	Game* const game;

public:

	UpdateCommand(Game* game) :game(game) {}
	virtual ~UpdateCommand() = default;

	virtual void exec() override;
};

class UninstallCommand : public ICommand {

private:

	Game* const game;

public:

	UninstallCommand(Game* game) :game(game) {}
	virtual ~UninstallCommand() = default;

	virtual void exec() override;
};
