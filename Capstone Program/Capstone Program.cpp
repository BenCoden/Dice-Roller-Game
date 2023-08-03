#include <iostream>
#include "Dice.h"
#include "DiceGame.h"

using namespace std;


int main() {

	DiceVector gameDice;

	DiceGame gameBoard(gameDice);

	gameBoard.StartGame();

	while (!gameBoard.IsGameOver()) {
	
		gameBoard.DisplayMenuSelectNextMove();
	
	};

	return 0;
}
