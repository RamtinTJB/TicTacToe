#include "game.h"

game::game() {
	players_[1].is_computer = get_bool("Do you wish to play against computer?");
	players_[0].name = get_entry("Enter Player 1's name");
	if (players_[1].is_computer) {
		players_[1].name = "Computer";
	} else {
		players_[1].name = get_entry("Enter Player 2's name");
	}
}

void game::make_move(int index) {
	put_sign(board_, index, signs[turn]);
	move_history_.push(index);
}

void game::move_and_switch(int index) {
	make_move(index);
	switch_turn();
}

void game::undo_move() {
	int index = move_history_.top();
	board_[index] = 0;
	move_history_.pop();
}

void game::undo_and_switch() {
	undo_move();
	switch_turn();
}

void game::loop() {
	while (!is_board_full(board_)) {
		std::cout << players_[turn].name << "'s turn (" << 
		   signs[turn] << ")" << std::endl;

		if (!players_[turn].is_computer) {
			int index = get_int_range("Enter your next move [1-9]", 1, 9) -1;
			if (!is_cell_empty(board_, index)) {
				std::cout << "Invalid input: that spot is already full." << std::endl;
				continue;
			}
			move_and_switch(index);
		} else {
			int best_move_index;
			minimax(*this, 0, true, Sides::O_SIDE, best_move_index);
			move_and_switch(best_move_index);
		}
		std::cout << *this << std::endl;
		if (win(board_, Sides::X_SIDE)) {
			std::cout << players_[0].name << " won!" << std::endl;
			break;
		} else if (win(board_, Sides::O_SIDE)) {
			std::cout << players_[1].name << " won!" << std::endl;
			break;
		} else if (is_board_full(board_)) {
			std::cout << "The game is a draw!" << std::endl;
			break;
		}
	}
}

std::vector<int> game::get_all_empty_slots() const {
	std::vector<int> res;
	for (int i = 0; i < 9; i++) {
		if (is_cell_empty(board_, i)) {
			res.push_back(i);
		}
	}

	return res;
}
