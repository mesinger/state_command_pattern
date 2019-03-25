#include "shopmenu.hpp"

Menu::Menu()
{
	games.emplace_back("apex legends");
	games.emplace_back("rainbow six");

	buyMenu = nullptr;
}

void Menu::buyGame(User* const user, std::string gamename)
{
	MenuItem buyMenu(std::make_shared<BuyCommand>(user, gamename));
	buyMenu.clicked();
}
