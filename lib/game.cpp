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