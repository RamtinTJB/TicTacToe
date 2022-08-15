#include "board.h"

bool is_index_valid(int index) {
	return index >= 0 && index <= 8;
}

bool is_cell_empty(const char brd[9], int index) {
	return brd[index] == 0;
}

bool is_board_full(const char brd[9]) {
	for (int i = 0; i < 9; i++) {
		if (is_cell_empty(brd, i)) return false;
	}
	return true;
}

bool win(const char brd[9], const Sides side) {
	for (int i = 0; i < 8; i++) {
		if (brd[win_indices[i][0]] == brd[win_indices[i][1]] &&
				brd[win_indices[i][0]] == brd[win_indices[i][2]] && 
				brd[win_indices[i][0]] != 0) {
			if (brd[win_indices[i][0]] == static_cast<char>(side)) {
				return true;
			}
		}
	}

	return false;
}

bool winning(const char brd[9]) {
	if (win(brd, Sides::X_SIDE) || win(brd, Sides::O_SIDE)) 
		return true;
	return false;
}

void put_sign(char brd[9], int index, char sign) {
	if (is_index_valid(index)) {
		brd[index] = sign;
	}
}

void print_board(const char brd[9], std::ostream& os) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int index = i*3 + j;
			if (is_cell_empty(brd, index)) {
				os << "-";
			} else {
				os << brd[index];
			}
		}
		os << std::endl;
	}
}

int next_possible_move(const char brd[9]) {
	if (is_board_full(brd)) return -1;

	for (int i = 0; i < 9; i++) {
		if (is_cell_empty(brd, i)) {
			return i;
		}
	}
}
