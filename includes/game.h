#ifndef GAME_H
#define GAME_H

#include "tictactoe.h"
#include "tttlibrary.h"

class Game {
public:
	static void Run();

	static void Play(const int& mode);

	static void PrintCommand();

	static bool ReplayConfirmation();
};


#endif