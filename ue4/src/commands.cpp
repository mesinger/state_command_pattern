#include "commands.hpp"
#include "shopmenu.hpp"

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

void BorrowCommand::exec()
{
	game->borrow();
}

void ReturnGameCommand::exec()
{
	game->returnGame();
}

OneClickPlayCommand::OneClickPlayCommand(Game * game)
	:game(game)
{
	add(std::make_unique<InstallCommand>(game));
	add(std::make_unique<StartCommand>(game));
}

BorrowGameToUserCommand::BorrowGameToUserCommand(User * owner, User * receiver, Game * game, Menu* shop)
	:game(game), owner(owner), receiver(receiver), shop(shop)
{
	add(std::make_unique<BorrowCommand>(game));
	add(std::make_unique<BuyCommand>(receiver, game->name));
	add(std::make_unique<BorrowGameShopCommands>(owner, receiver, game, shop));
}

BorrowGameShopCommands::BorrowGameShopCommands(User * owner, User * receiver, Game * game, Menu * shop)
	:game(game), owner(owner), receiver(receiver), shop(shop)
{
	add(std::make_unique<BorrorwGameShopStorageCommand>(owner, receiver, game->name, shop));
}

BorrorwGameShopStorageCommand::BorrorwGameShopStorageCommand(User * owner, User * receiver, const std::string& gamename, Menu * shop)
	: gamename(gamename), owner(owner), receiver(receiver), shop(shop)
{
}

void BorrorwGameShopStorageCommand::exec()
{
	shop->addBorrowedGameToDataBase(owner, receiver, gamename);
}

ReturnGameByOwnerCommand::ReturnGameByOwnerCommand(User * owner, User * receiver, const std::string& gamename, Menu * shop)
	:owner(owner), receiver(receiver), gamename(gamename), shop(shop)
{
	Game* ownersGame = owner->getGame(gamename);
	Game* receiversGame = receiver->getGame(gamename);

	add(std::make_unique<StopCommand>(receiversGame));
	add(std::make_unique<UninstallCommand>(receiversGame));
	add(std::make_unique<ReturnGameCommand>(ownersGame));
	add(std::make_unique<RemoveGameCommand>(shop, receiver, gamename));
	add(std::make_unique<ReturnGameShopStorageCommand>(owner, receiver, gamename, shop));
}

ReturnGameByReceiverCommand::ReturnGameByReceiverCommand(User * owner, User * receiver, const std::string& gamename, Menu * shop)
	:owner(owner), receiver(receiver), gamename(gamename), shop(shop)
{
	Game* ownersGame = owner->getGame(gamename);
	Game* receiversGame = receiver->getGame(gamename);

	add(std::make_unique<StopCommand>(receiversGame));
	add(std::make_unique<UninstallCommand>(receiversGame));
	add(std::make_unique<ReturnGameCommand>(ownersGame));
	add(std::make_unique<RemoveGameCommand>(shop, receiver, gamename));
	add(std::make_unique<ReturnGameShopStorageCommand>(owner, receiver, gamename, shop));
}

ReturnGameShopStorageCommand::ReturnGameShopStorageCommand(User * owner, User * receiver, const std::string& gamename, Menu * shop)
	: gamename(gamename), owner(owner), receiver(receiver), shop(shop)
{
}

void ReturnGameShopStorageCommand::exec()
{
	shop->removeBorrowedGameFromDataBase(owner, receiver, gamename);
}

void RemoveGameCommand::exec()
{
	shop->removeGame(user, gamename);
}
