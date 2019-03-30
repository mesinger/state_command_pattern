#include "shopmenu.hpp"

Menu::Menu()
{
	games.emplace_back("apex legends");
	games.emplace_back("rainbow six");
}

void Menu::buyGame(User* user, const std::string& gamename)
{
	MenuItem buyMenu(std::make_shared<BuyCommand>(user, gamename));
	buyMenu.clicked();
}

void Menu::installGame(Game * pgame)
{
	MenuItem installMenu(std::make_shared<InstallCommand>(pgame));
	installMenu.clicked();
}

void Menu::updateGame(Game * pgame)
{
	MenuItem updateMenu(std::make_shared<UpdateCommand>(pgame));
	updateMenu.clicked();
}

void Menu::startGame(Game * pgame)
{
	MenuItem startMenu(std::make_shared<StartCommand>(pgame));
	startMenu.clicked();
}

void Menu::stopGame(Game * pgame)
{
	MenuItem stopMenu(std::make_shared<StopCommand>(pgame));
	stopMenu.clicked();
}

void Menu::uninstallGame(Game * pgame)
{
	MenuItem uninstallMenu(std::make_shared<UninstallCommand>(pgame));
	uninstallMenu.clicked();
}

void Menu::oneclickplay(Game * pgame)
{
	OneClickPlayCommand cmd(pgame);
	cmd.exec();
}

void Menu::borrow(User * owner, User * receiver, Game * game)
{
	BorrowGameToUserCommand cmd(owner, receiver, game, this);
	cmd.exec();
}

void Menu::returnGameByOwner(User * owner, User * receiver, Game * game)
{
	//async call

	ReturnGameByOwnerCommand cmd(owner, receiver, game->name, this);
	cmd.exec();
}

void Menu::returnGameByReceiver(User * owner, User * receiver, Game * game)
{
	ReturnGameByReceiverCommand cmd(owner, receiver, game->name, this);
	cmd.exec();
}

void Menu::removeGame(User * user, const std::string & gamename) const
{
	user->removeGame(gamename);
}

void Menu::addBorrowedGameToDataBase(User * owner, User * receiver, const std::string& gamename)
{
	//add this to a database
	std::string msg;
	msg += "borrowed " + gamename;
	borrowedGamesLog.push_back(msg);
}

void Menu::removeBorrowedGameFromDataBase(User * owner, User * receiver, const std::string& gamename)
{
	//remove this from a database
	std::string msg;
	msg += "returned " + gamename;
	borrowedGamesLog.push_back(msg);
}
