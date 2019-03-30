#include "commands.hpp"

void BuyCommand::exec()
{
	receiver->addGame(gamename);
}

void InstallCommand::exec()
{
	game->install();
}

void StartCommand::exec()
{
	game->start();
}

void UpdateCommand::exec()
{
	game->update();
}

void UninstallCommand::exec()
{
	game->uninstall();
}

void StopCommand::exec()
{
	game->stop();
}

OneClickPlayCommand::OneClickPlayCommand(Game * game)
	:game(game)
{
	add(std::make_unique<InstallCommand>(game));
	add(std::make_unique<StartCommand>(game));
}
