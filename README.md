# TicTacToe
An unbeatable game of TicTacToe implemented using the minimax algorithm.

## A Brief Overview of the Minimax Algorithm
Minimax is a recursive algorithm used in decision making to find the best move for a player in the current state of the game. At the core of this algorithm is the evaluate (or score in this program) function whose job is to calculate the score of the game state based on some predetermined criteria. In my TicTacToe game, the `score` function only checks if one side is winning and returns a positive value if the winning side is the computer. If the game hasn't ended yet, the `score` function returns 0. I also took the depth into account, so that a win in 2 moves in preferable over a win in 3 moves (e.g. a win for the computer in 3 moves has a score of 7,  a win for the human player in 2 moves has a score of -8).
```cpp
int score(char brd[9], const Sides& side);
```

The `minimax` function iterates over all the possible moves, calls the `score` function on the resulting game state, and recursively calls itself for every possible move. After collecting all the scores for all the moves, it selects the best one. The computer is the maximizer so it will choose the move with the highest positive score, and the player is the minimizer so it will choose the move with the largest negative score. at every stage the chosen move is stored in `best_move` and after the function call is over, the value of `best_move` reflects the best move for the computer at the current state of the TicTacToe game.
```cpp
int minimax(game g, int depth, bool is_maximizer, const Sides& side, int& best_move);
```

## Build and Run
This program uses `C++17` and `CMake 3.12`. To build and run:

```
git clone https://github.com/ramtintjb/tictactoe
cd tictactoe
cmake -B build
cd build
make
src/TicTacToe
```

## License

<img align="right" src="https://opensource.org/trademarks/opensource/OSI-Approved-License-100x137.png">

The project is licensed under the [MIT License](https://opensource.org/licenses/MIT):

Copyright &copy; 2022 Ramtin Tajbakhsh
