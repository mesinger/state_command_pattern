#include "shopmenu.hpp"
#include <iostream>
#include <string>
#include <string>
#include <memory>

int main(int argc, char** argv) {

	User mesi(1);
	Menu shop(&mesi);

	shop.buyGame("apex");
	shop.startGame(mesi.getGame("apex"));
	shop.installGame(mesi.getGame("apex"));
	shop.startGame(mesi.getGame("apex"));
	shop.updateGame(mesi.getGame("apex"));
	shop.stopGame(mesi.getGame("apex"));
	shop.updateGame(mesi.getGame("apex"));
	shop.stopGame(mesi.getGame("apex"));
	shop.uninstallGame(mesi.getGame("apex"));

	return EXIT_SUCCESS;
}