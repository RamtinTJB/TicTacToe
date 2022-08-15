#include "minimax.h"

int score(char brd[9], const Sides& side, int depth) {
	if (win(brd, side)) {
		return 10 - depth;
	} else if (win(brd, other_side(side))) {
		return -10 + depth;
	} else {
		return 0;
	}
}

int minimax(game g, int depth, bool is_maximizer, const Sides& comp_side, int& best_move) {
	if (is_board_full(g.get_board()) || winning(g.get_board())) {
		return score(g.get_board(), comp_side, depth);
	}

	std::vector<int> scores;
	std::vector<int> moves;

	for (const auto& move: g.get_all_empty_slots()) {
		g.move_and_switch(move);

		scores.push_back(minimax(g, depth+1, !is_maximizer, comp_side, best_move));
		moves.push_back(move);

		g.undo_and_switch();
	}


	if (is_maximizer) {
		int maximum_index = std::distance(scores.begin(),
				std::max_element(scores.begin(), scores.end()));
		best_move = moves[maximum_index];
		return scores[maximum_index];
	} else {
		int minimum_index = std::distance(scores.begin(),
				std::min_element(scores.begin(), scores.end()));
		best_move = moves[minimum_index];
		return scores[minimum_index];
	}
}
