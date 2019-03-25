#include "commands.hpp"

void BuyCommand::exec()
{
	receiver->addGame(gamename);
}
