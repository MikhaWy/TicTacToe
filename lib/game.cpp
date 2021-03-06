#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

#include "../includes/tictactoe.h"
#include "../includes/tttlibrary.h"
#include "../includes/game.h"

void Game::Run() {
    srand((unsigned int)time(NULL));
    std::string command;

    bool play = true;
    while (play) {
        Game::PrintCommand();
	    std::cout << std::endl << "Select command: ";
	    std::getline(std::cin, command);

	    if (command[0] == '1') {
	    	Game::Play(SINGLE_PLAYER);
	    	play = Game::ReplayConfirmation();
	    }
	    else if (command[0] == '2') {
        	Game::Play(MULTI_PLAYER);
            play = Game::ReplayConfirmation();
	    }
        else if (command[0] == '3') {
            play = false;
	    }
	    else {
		    std::cout << "Invalid command! Try again..." << std::endl << std::endl;
	    }
    }

    std::cout << "Thank you for playing..." << std::endl;
    exit(EXIT_SUCCESS);
}

void Game::PrintCommand() {
    std::cout << "Select playing mode:" << std::endl;
    std::cout << "[1] Singleplayer vs A.I." << std::endl;
    std::cout << "[2] Multiplayer" << std::endl;
    std::cout << "[3] Exit" << std::endl;
}

void Game::Play(const int& mode) {
    tictactoe_t tictactoe;
    int totalMove = 0;

    if (mode == SINGLE_PLAYER) {
        // Randomly choose the starting player
	    // Even number will be player's turn, odd will be A.I.'s turn
	    bool player = (rand() % 2 + 1) % 2 == 0;
        
        TTTLibrary::PrintBoard(tictactoe);
	    std::cout << "First player will be: " << (player ? "You" : "A.I.") << std::endl;

	    std::string move;
	    while (!tictactoe.gameEnd) {
		    // Currently it's player's turn
		    if (player) {
			    std::cout << "Select location (e.g. A3): ";
			    std::getline(std::cin, move);

			    const char* move_c = const_cast<char*>(move.c_str());
			    if (TTTLibrary::isLegalMove(tictactoe, move_c)) {
				    TTTLibrary::UpdateBoard(tictactoe, move_c);
				    TTTLibrary::PrintBoard(tictactoe);

				    player = !player;
				    tictactoe.turn = !tictactoe.turn;
				    tictactoe.gameStatus = TTTLibrary::EvaluateBoard(tictactoe);
				    totalMove++;
			    }
			    else {
				    std::cout << "Illegal move! Try again..." << std::endl;
				    continue;
			    }
		    }
            // A.I. will call minimax algorithm to select best move
		    else {
			    char* move_c = TTTLibrary::BestMove(tictactoe);
			    TTTLibrary::UpdateBoard(tictactoe, move_c);

			    std::cout << "A.I. selected location: " << move_c << std::endl;
			    TTTLibrary::PrintBoard(tictactoe);

			    player = !player;
			    tictactoe.turn = !tictactoe.turn;
			    tictactoe.gameStatus = TTTLibrary::EvaluateBoard(tictactoe);
			    totalMove++;

			    delete[] move_c;
		    }
            
		    // Stop the current round if totalMove is more than 9
		    if (totalMove == BOARD_SIZE * BOARD_SIZE || tictactoe.gameStatus != 0)
			    tictactoe.gameEnd = true;
        }
    }
    else if (mode == MULTI_PLAYER) {
        TTTLibrary::PrintBoard(tictactoe);

	    std::string move;
	    while (!tictactoe.gameEnd) {
            
		    if (tictactoe.turn)
			    std::cout << "Enter the next move for player X (e.g. A3): ";
		    else
			    std::cout << "Enter the next move for player O (e.g. A3): ";
		    std::getline(std::cin, move);

		    const char* move_c = const_cast<char*>(move.c_str());
		    if (TTTLibrary::isLegalMove(tictactoe, move_c)) {
			    TTTLibrary::UpdateBoard(tictactoe, move_c);
			    TTTLibrary::PrintBoard(tictactoe);

			    tictactoe.gameStatus = TTTLibrary::EvaluateBoard(tictactoe);
			    tictactoe.turn = !tictactoe.turn;
			    totalMove++;
		    }
		    else {
			    std::cout << "Illegal move! Try again..." << std::endl;
			    continue;
		    }

		    // Stop the current round if totalMove is more than 9
		    if (totalMove == BOARD_SIZE * BOARD_SIZE || tictactoe.gameStatus != 0)
			    tictactoe.gameEnd = true;
        }
    }

    if (tictactoe.gameStatus == 0)
	    std::cout << "GAME END: Tie!..." << std::endl;
	else if (tictactoe.gameStatus < 0)
	    std::cout << "GAME END: Winner: Player O!" << std::endl;
	else if (tictactoe.gameStatus > 0)
	    std::cout << "GAME END: Winner: Player X!" << std::endl;
	else
	    std::cout << "ERROR: Game status invalid!" << std::endl;
}

bool Game::ReplayConfirmation() {
    std::string confirmation;
    std::cout << "Continue again (Y/y)? ";
    std::getline(std::cin, confirmation);

    if (toupper(confirmation[0]) == 'Y')
	    return true;
    return false;
}