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
        bool player = 1;
        
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
            else {
                //AI move
            }
        }
    }
    else if (mode == MULTI_PLAYER) {
        // Loop with 2 players
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