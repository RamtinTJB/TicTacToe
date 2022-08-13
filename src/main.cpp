#include <iostream>
#include "board.h"
#include "game.h"

int main(int argc, const char** argv) {
	std::cout << "Tic Tac Toe" << std::endl;

	game g;
	g.loop();

	std::cout << std::endl;

	return 0;
}
