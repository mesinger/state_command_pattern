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


