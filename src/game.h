#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H

#include <iostream>
#include <vector>
#include <stack>

#include "board.h"
#include "input.h"
#include "minimax.h"

struct player {
	std::string name;
	bool is_computer = false;
};

class game {
	private:
		char* board_ = new char[9];
		player* players_ = new player[2];
		std::stack<int> move_history_;
		int turn = 0;

		const char signs[2] = {'x', 'o'};
	public:
		game();
	
		void switch_turn() { turn ^= 1; }
		void make_move(int index);
		void move_and_switch(int index);
		void undo_move();
		void undo_and_switch();

		void loop();

		char* get_board() const { return board_; }

		// returns a vector of all the available moves for the current position
		std::vector<int> get_all_empty_slots() const;
};

inline std::ostream& operator<< (std::ostream& os, const game& g) {
	print_board(g.get_board(), os);
	return os;
}

#endif
