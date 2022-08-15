#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H

#include <iostream>
#include <vector>
#include <stack>

enum class Sides {
	X_SIDE = 'x', O_SIDE = 'o' 
};

inline Sides other_side(const Sides& side) {
	if (side == Sides::X_SIDE) return Sides::O_SIDE;
	return Sides::X_SIDE;
}

inline int win_indices[8][3] = {
	{0,1,2}, {3,4,5}, {6,7,8},
	{0,3,6}, {1,4,7}, {2,5,8},
	{0,4,8}, {2,4,6}
};

bool is_index_valid(int index);
bool is_cell_empty(const char*, int index);
bool is_board_full(const char*);

bool win(const char*, const Sides);
bool winning(const char*);

void put_sign(char*, int index, char sign);
void print_board(const char*, std::ostream&);

int next_possible_move(const char*);

#endif
