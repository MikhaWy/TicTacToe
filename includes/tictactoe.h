#ifndef TICTACTOE_H
#define TICTACTOE_H

#define		DEFAULT_MODE	0
#define		SINGLE_PLAYER	0
#define		MULTI_PLAYER	1
#define		BOARD_SIZE		3
#define		SEARCH_DEPTH	9 // 3 * 3

typedef		unsigned char board_t[BOARD_SIZE][BOARD_SIZE];

typedef struct TicTacToe {
	// Holds an instance of board of 3X3
	board_t board;

	// The current state of the game
	bool gameEnd = false;

	// X's turn := true
	// O's turn := false
	bool turn = true; // Always start with 'X'
	
	// Game status holds the final status of the board:
	// 0: Tie
	// 1: X Wins (Maximizer)
	// 2: O Wins (Minimizer)
	int gameStatus = 0;

	TicTacToe() {
		for (int i = 0; i < BOARD_SIZE; i++)
			for (int j = 0; j < BOARD_SIZE; j++)
				board[i][j] = ' ';
	}

} tictactoe_t;

#endif