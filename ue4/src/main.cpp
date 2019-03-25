#include "Game.h"
#include <iostream>
#include <string>

int main(int argc, char** argv) {

	Game game("apex legends");

	game.start();
	game.install();
	game.uninstall();

	game.buy();
	game.uninstall();
	game.install();
	game.stop();
	game.start();
	game.update();
	game.stop();
	game.uninstall();

	return EXIT_SUCCESS;
}