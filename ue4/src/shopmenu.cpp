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
