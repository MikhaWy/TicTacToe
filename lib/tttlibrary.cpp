#include <iostream>
#include <stdlib.h>
#include <climits>

#include "../includes/tttlibrary.h"
#include "../includes/tictactoe.h"

void TTTLibrary::ResetBoard(tictactoe_t& board) {
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			board.board[i][j] = ' ';
}

void TTTLibrary::PrintBoard(const tictactoe_t& board) {
	std::cout << std::endl << "     A   B   C" << std::endl;
	std::cout << "   +---+---+---+" << std::endl;

	for (int i = 0; i < BOARD_SIZE; i++) {
		std::cout << " " << (i + 1) << " |";
		for (int j = 0; j < BOARD_SIZE; j++)
			std::cout << " " << board.board[i][j] << " |";
		std::cout << std::endl << "   +---+---+---+" << std::endl;
	}
	std::cout << std::endl;
}

void TTTLibrary::UpdateBoard(tictactoe_t& board, const char* move) {
	// move = B1
	int row = move[1] - '1'; // 0
	int col = move[0] - 'A'; // 1

	if (board.turn)
		board.board[row][col] = 'X';
	else
		board.board[row][col] = 'O';
}

int TTTLibrary::GetEmptyGrid(const tictactoe_t& board) {
	int index = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			if (board.board[i][j] == ' ')
				index++;
	return index;
}

bool TTTLibrary::isLegalMove(const tictactoe_t& board, const char* move) {
	// Rules of legal moves:
	// 1. Move must not be out of bound
	// 2. Target position must be ' '

	int row = move[1] - '1';
	int col = move[0] - 'A';

	// Index out of bound check
	if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE)
		return false;

	// Check if target position is empty
	if (board.board[row][col] != ' ')
		return false;

	return true;
}

int TTTLibrary::EvaluateBoard(tictactoe_t& board) {
	// Check for horizontal wil condition
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (board.board[i][0] == board.board[i][1] && board.board[i][0] == board.board[i][2]) {
			if (board.board[i][0] == 'X') {
				board.gameEnd = true;
				return TTTLibrary::GetEmptyGrid(board) + 1;
			}
			else if (board.board[i][0] == 'O') {
				board.gameEnd = true;
				return -(TTTLibrary::GetEmptyGrid(board) + 1);
			}
		}
	}

	// Check for vertical win condition
	for (int j = 0; j < BOARD_SIZE; j++) {
		if (board.board[0][j] == board.board[1][j] && board.board[0][j] == board.board[2][j]) {
			if (board.board[0][j] == 'X') {
				board.gameEnd = true;
				return TTTLibrary::GetEmptyGrid(board) + 1;
			}
			else if (board.board[0][j] == 'O') {
				board.gameEnd = true;
				return -(TTTLibrary::GetEmptyGrid(board) + 1);
			}
		}
	}

	// Check for diagonal win condition
	if (board.board[0][0] == board.board[1][1] && board.board[0][0] == board.board[2][2]) {
		if (board.board[0][0] == 'X') {
			board.gameEnd = true;
			return TTTLibrary::GetEmptyGrid(board) + 1;
		}
		else if (board.board[0][0] == 'O') {
			board.gameEnd = true;
			return -(TTTLibrary::GetEmptyGrid(board) + 1);
		}
	}
	if (board.board[0][2] == board.board[1][1] && board.board[0][2] == board.board[2][0]) {
		if (board.board[0][2] == 'X') {
			board.gameEnd = true;
			return TTTLibrary::GetEmptyGrid(board) + 1;
		}
		else if (board.board[0][2] == 'O') {
			board.gameEnd = true;
			return -(TTTLibrary::GetEmptyGrid(board) + 1);
		}
	}

	// Check if there are still possible empty move
	if (TTTLibrary::GetEmptyGrid(board) == 0) // Game is Tied
		board.gameEnd = true;
	return 0;
}
