#include "shopmenu.hpp"
#include <iostream>
#include <string>
#include <string>
#include <memory>

int main(int argc, char** argv) {

	Menu shop;
	User mesi(1);

	shop.buyGame(&mesi, "apex legends");

	return EXIT_SUCCESS;
}