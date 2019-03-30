#include "shopmenu.hpp"
#include <iostream>
#include <string>
#include <string>
#include <memory>

int main(int argc, char** argv) {

	User mesi(1);
	Menu shop;

	//shop.buyGame(&mesi, "apex");
	//shop.installGame(mesi.getGame("apex"));
	//shop.startGame(mesi.getGame("apex"));
	//shop.stopGame(mesi.getGame("apex"));
	//shop.uninstallGame(mesi.getGame("apex"));

	shop.buyGame(&mesi, "apex");
	shop.oneclickplay(mesi.getGame("apex"));

	return EXIT_SUCCESS;
}