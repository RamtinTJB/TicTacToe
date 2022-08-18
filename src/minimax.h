#ifndef TIC_TAC_TOE_MINIMAX_H
#define TIC_TAC_TOE_MINIMAX_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

#include "game.h"
#include "board.h"

class game;

// evaluates the board and returns the score
// returns a positive value if (side) has an advantage or has won
// returns a negative value if the other side has an advantage
int score(char*, const Sides& side);

// The algorithm behind an unbeatable game of TicTacToe
// After the algorithm is done, the best move is stored in (best_move)
// In this algorithm, computer is always the maximizer and its goal is to choose the 
// move that maximizes the score of the board.
int minimax(game g, int depth, bool is_maximizer, const Sides& comp_side, int& best_move);

#endif
