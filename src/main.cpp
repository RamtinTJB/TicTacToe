#include <iostream>
#include "board.h"
#include "game.h"
#include "minimax.h"

int main(int argc, const char** argv) {
	std::cout << "Tic Tac Toe" << std::endl;

	game g;
	g.loop();
	
	return 0;
}
