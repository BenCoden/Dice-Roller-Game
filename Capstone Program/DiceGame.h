#pragma once

#include "Dice.h"
#include "GameBase.h"
#include <vector>

using namespace std;

class DiceGame : private GameBase
{
	int numDice = 0;
	const int maxNumberDice = 15;
	const int maxNumberSide = 20;
	DiceVector& diceArray;
	enum MenuItems { RollAgain, 
					ChangeDiceSides,
					FindSum,
					FindAgerage,
					DropHeighest,
					DropLowest,
					EndGame, 
					COUNT };
	MenuItems SelectedNextMove = MenuItems::RollAgain;

	void FindDisplayDiceSum();
	int FindDiceSum();
	void DropLowestDice();
	void FindDisplayDiceAgerage();
	void DoSelectItemFromMenu();
	void DisplayDoSelecetShortMenu();
	void SetDice();
	void RollingDice();
	void EndProgram();
	void ChangeDiceSide();
	void ReadyToRollDice();
	void DropHeighestDice();
public:
	DiceGame(DiceVector&);
	void DisplayMenuSelectNextMove();
	void StartGame();
	bool isGameOver();
};

