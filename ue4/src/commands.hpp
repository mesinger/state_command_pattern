#pragma once

#include "User.hpp"
#include "Game.hpp"
#include "composite.h"

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

class OneClickPlayCommand : public CommandComposite {

private:

	Game* const game;

public:

	OneClickPlayCommand(Game* game);
	virtual ~OneClickPlayCommand() = default;
};
