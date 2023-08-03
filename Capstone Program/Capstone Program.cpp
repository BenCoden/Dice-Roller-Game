#include <iostream>
#include "Dice.h"
#include "DiceGame.h"

using namespace std;


int main() {

	DiceVector gameDice;

	DiceGame gameBoard(gameDice);

	gameBoard.StartGame();

	while (!gameBoard.isGameOver()) {
	
		gameBoard.DisplayMenuSelectNextMove();
	
	};

	return 0;
}
