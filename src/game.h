#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H

#include <iostream>
#include "board.h"
#include "input.h"

struct player {
	std::string name;
	bool is_computer = false;
};

class game {
	private:
		char* board_ = new char[9];
		player* players_ = new player[2];
		int turn = 0;

		const char signs[2] = {'x', 'o'};
	public:
		game() = default;
	
		void switch_turn() { turn ^= 1; }
		void make_move(int index);

		void loop();

		char* get_board() const { return board_; }
};

inline std::ostream& operator<< (std::ostream& os, const game& g) {
	print_board(g.get_board(), os);
	return os;
}

#endif
