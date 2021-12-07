#ifndef TTTLIBRARY_H
#define TTTLIBRARY_H

#include "tictactoe.h"

class TTTLibrary {
public:
	// ResetBoard: Reset and fill the given board with ' '
	static void ResetBoard(tictactoe_t& board);

	// PrintBoard: Print the given board
	static void PrintBoard(const tictactoe_t& board);

	// UpdateBoard: Fills the current board, given the move is a legal move
	static void UpdateBoard(tictactoe_t& board, const char* move);

	// GetEmptyGrid: Fills the given list with all possible empty grid
	//				 Then return the size of array as a buddy variable
	static int GetEmptyGrid(const tictactoe_t& board);

	// isLegalMove: Returns true if the given coordinate is empty (unfilled)
	static bool isLegalMove(const tictactoe_t& board, const char* move);

	// EvaluateBoard: Evaluate and return the current score of the board
	// (+1) X Wins, (-1) O Wins, (0) Tie
	static int EvaluateBoard(tictactoe_t& board);

	// BestMove: Return the best next move using the minimax algorithm
	static char* BestMove(tictactoe_t position);

private:

	// MiniMax: Minimax algorithm will evaluate the current position of the
	//			board and return the most optimal for the current player
	static int MiniMax(tictactoe_t& position, const int& depth, const bool& maximizingPlayer);
};
//1
#endif