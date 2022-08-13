#include "game.h"

void game::make_move(int index) {
	put_sign(board_, index, signs[turn]);
}

void game::loop() {
	while (!is_board_full(board_)) {
		if (!players_[turn].is_computer) {
			int index = get_int("Enter your next move [1-9]");
			if (!is_cell_empty(board_, index)) {
				std::cout << "Invalid input: that spot is already full." << std::endl;
				continue;
			}
			make_move(index);
		} else {
		}
		if (win(board_, Sides::X_SIDE)) {
			std::cout << players_[0].name << " won!" << std::endl;
			break;
		} else if (win(board_, Sides::O_SIDE)) {
			std::cout << players_[1].name << " won!" << std::endl;
			break;
		}
		std::cout << *this;
		switch_turn();
	}
}
