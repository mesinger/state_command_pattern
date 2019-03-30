#include "shopmenu.hpp"
#include <iostream>
#include <string>
#include <string>
#include <memory>

int main(int argc, char** argv) {

	User mesi(1);
	User ben(2);
	Menu shop;

	//shop.buyGame(&mesi, "apex");
	//shop.installGame(mesi.getGame("apex"));
	//shop.startGame(mesi.getGame("apex"));
	//shop.stopGame(mesi.getGame("apex"));
	//shop.uninstallGame(mesi.getGame("apex"));

	shop.buyGame(&mesi, "apex");
	shop.installGame(mesi.getGame("apex"));
	shop.borrow(&mesi, &ben, mesi.getGame("apex"));

	shop.startGame(mesi.getGame("apex"));
	shop.installGame(ben.getGame("apex"));
	shop.startGame(ben.getGame("apex"));

	shop.returnGameByOwner(&mesi, &ben, mesi.getGame("apex"));
	shop.startGame(mesi.getGame("apex"));

	return EXIT_SUCCESS;
}