#ifndef TIC_TAC_TOE_MINIMAX_H
#define TIC_TAC_TOE_MINIMAX_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

#include "game.h"
#include "board.h"

class game;

int score(char*, const Sides& side);
int minimax(game g, int depth, bool is_maximizer, const Sides& comp_side, int& best_move);

#endif
