# TicTacToe  
by Edrick, **Mikha**, Roger  
COMP2424-A Data Structures & Algorithms
Mr. Muhamad Rausyan Fikri
Date of Submission: 07 December, 2021

## Project Overview
The tic tac toe game is a famous simple game that is playable by two opposing players, one represents the character 'X' while the other 'O'. With modern computing, players can now play the game against an “artificial intelligence”. The first iteration of the A.I. uses random slot selection and this makes the game “not challenging”, this gave birth to an algorithm called the minimax algorithm.  
The minimax algorithm is a backtracking algorithm that optimizes the best next move for a player to take. Minimax only works for games with two players as each player will act as a minimizing player and a maximizing player. With tic tac toe, where there are only two players, minimax can be implemented for the computer to go against the opposing player. During the A.I.’s turn, minimax algorithm will generate and evaluate all possible move up to the depth given or when the algorithm reaches a solution that require less steps. These possible move generated can be visualized and be travelled in a form of a tree data structure.

## Clone Project
```
> git clone https://github.com/MikhaWy/TicTacToe.git
```

## Compiling and Running
```
> cd build
> make
```

## Project Structure
Folders in this project include:
1. build
1. docs
1. includes
1. lib
1. src

### Build Folder
The batch file make.bat will contain the original compile function
```
> g++ -o main ../src/main.cpp ../lib/game.cpp ../lib/tttlibrary.cpp
> main
```
This folder will also contain the compiled .exe file, called main.

### Document Folder
Document folder will contain the used images and report file.

### Includes Folder
Contain header (.h) files

### Lib Folder
Contain library files (.cpp) for the header (.h) files.

### Src Folder
Contain the main function and the main.cpp file.

## Sample Input and Output
### vs A.I.
![Image](docs\img\IO1.png)
![Image](docs\img\IO2.png)
![Image](docs\img\IO3.png)
### vs Human
![Image](docs\img\IO4.png)
![Image](docs\img\IO5.png)
