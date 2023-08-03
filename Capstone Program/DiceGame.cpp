#include "DiceGame.h"
#include "Dice.h"
#include "DisplayColor.h"

#include "GameBase.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

DiceGame::DiceGame(DiceVector& diceArrayRef) : diceArray(diceArrayRef)
{

	cout << "====================================================" << endl;
	cout << "         Welcome to the Dice Game" << endl;
	cout << "====================================================" << endl;
	cout << endl;
	cout << "Get ready to roll the dice and have fun!" << endl;
	cout << endl;
	cout << "You can pick up to " << maxNumberDice << " dice to roll at once." << endl;
	cout << endl;
	cout << "Each dice can have upto " << maxNumberSide << " sides." << endl;
	cout << endl;
}

void DiceGame::StartGame()
{
	do
	{
		cout << "Enter the number of dice: ";
		cin >> numDice;
	} while (!validateInput(numDice, maxNumberDice));

	this->SetDice();

	this->ReadyToRollDice();
}

bool DiceGame::isGameOver()
{
	return gameOver;
}

void DiceGame::SetDice()
{
	for (int i = 0; i <= numDice - 1; i++)
	{
		int  numSides = -1;

		do
		{
			cout << "Enter the number of sides for dice number " << i + 1 << " : ";
			cin >> numSides;
		} while (!validateInput(numSides, maxNumberSide));

		diceArray.push_back(Dice(numSides));
	}
}

void DiceGame::RollingDice()
{
	for (int i = 0; i <= diceArray.size() - 1; i++) 
		diceArray[i].rollDice();
	
	cout << diceArray;
}

void DiceGame::ReadyToRollDice()
{
	char  isRolling;

	do
	{
		cout << "Are you redy to roll? (y/n)";
		cin >> isRolling;
	} while (!(isRolling == 'y' || isRolling == 'Y' || isRolling == 'N' || isRolling == 'n'));

	if (isRolling == 'y' || isRolling == 'Y')
	{
		this->RollingDice();
	}
	else
	{
		this->DisplayDoSelecetShortMenu();
	}
}

void DiceGame::DropLowestDice()
{
	int indexOfHighestDie = -1;
	int lowDieSide = 99;
	if (diceArray.isVisableSize() > 1) {
		for (int i = 0; i < diceArray.size(); i++) {
			int currentDieSide = diceArray[i].getLandedSide();
			if (currentDieSide < lowDieSide && diceArray[i].isVisable) {
				lowDieSide = currentDieSide;
				indexOfHighestDie = i;
			}
		}

			diceArray[indexOfHighestDie].isVisable = false;

			DisplayColor::PrintWithColor("Dropped the die with the lowest value.", DisplayColor::Color::GREEN);
			cout << endl;

			cout << diceArray;
		
	}
	else {
		DisplayColor::PrintWithColor("No die left to drop. Please roll again", DisplayColor::Color::GREEN);
		cout << endl;
	}
}

void DiceGame::DropHeighestDice()
{
	
		int indexOfHighestDie = -1;
		int maxDieSide = -1;
		if (diceArray.isVisableSize() > 1) {
			for (int i = 0; i < diceArray.size(); i++) {
				int currentDieSide = diceArray[i].getLandedSide();
				if (currentDieSide > maxDieSide && diceArray[i].isVisable) {
					maxDieSide = currentDieSide;
					indexOfHighestDie = i;
					
				}
			}
			diceArray[indexOfHighestDie].isVisable = false;

			DisplayColor::PrintWithColor("Dropped the die with the highest value.", DisplayColor::Color::GREEN);	
			cout << endl;

			cout << diceArray;
		}
		else {
			DisplayColor::PrintWithColor("No die left to drop. Please roll again", DisplayColor::Color::GREEN);
			cout << endl;
		}
	
		
	
}



void DiceGame::DisplayDoSelecetShortMenu() {
	int maxMenuNumber = 2;
	int nextMove;

	do
	{
		cout << "1. Change number of sides" << endl;
		cout << "2. End game" << endl;
		cout << "Enter your choice: ";
		cin >> nextMove;
	} while (!validateInput(nextMove, maxMenuNumber));

	switch (nextMove)
	{
	case 1:
		this->ChangeDiceSide();
		this->ReadyToRollDice();
		break;
	case 2:
		this->EndProgram();
		break;
	default:
		break;
	}

}

void DiceGame::DisplayMenuSelectNextMove() {
	int nextMove;
	do
	{
		cout << "1. Roll again" << endl;
		cout << "2. Change number of sides" << endl;
		cout << "3. Find Sum" << endl;
		cout << "4. Find Agverage" << endl;
		cout << "5. Drop Highest" << endl;
		cout << "6. Drop Lowest" << endl;
		cout << "7. End game" << endl;
		cout << "Enter your choice: ";
		cin >> nextMove;
	} while (!validateInput(nextMove, static_cast<size_t>(MenuItems::COUNT)));

	SelectedNextMove = static_cast<MenuItems>(nextMove - 1);

	this->DoSelectItemFromMenu();
}

void DiceGame::EndProgram() {
	gameOver = true;
}

void DiceGame::ChangeDiceSide()
{
	for (int i = 0; i <= diceArray.size() - 1; i++)
	{
		int  numSides = -1;

		do
		{
			cout << "Enter the number to change die " << i + 1 << " : ";
			cin >> numSides;
		} while (!validateInput(numSides, maxNumberSide));

		diceArray[i].changeSideNumber(numSides);
	}
}
void DiceGame::FindDisplayDiceSum()
{
	DisplayColor::PrintWithColor("The Sum of your last roll is: " + to_string(FindDiceSum()), DisplayColor::Color::GREEN);
	cout << endl;
}

int DiceGame::FindDiceSum()
{
	int sum = 0;
	for (int i = 0; i <= diceArray.size() - 1; i++) {
		if (diceArray[i].isVisable)
		{
			sum = sum + diceArray[i].getLandedSide();
		}
	}
	return sum;
}

void DiceGame::FindDisplayDiceAgerage()
{
	int sum = FindDiceSum();
	int agerage = sum / diceArray.isVisableSize();
	int remainder = sum % diceArray.isVisableSize();
	DisplayColor::PrintWithColor("The Agerage of your last roll is: " + to_string(agerage) + " with a remainder of: " + to_string(remainder), DisplayColor::Color::GREEN);
	cout << endl;
}

void DiceGame::DoSelectItemFromMenu() {
	switch (SelectedNextMove)
	{
	case MenuItems::RollAgain:
		this->RollingDice();
		break;
	case MenuItems::ChangeDiceSides:
		this->ChangeDiceSide();
		break;
	case MenuItems::FindSum:
		this->FindDisplayDiceSum();
		break;
	case MenuItems::FindAgerage:
		this->FindDisplayDiceAgerage();
		break;
	case MenuItems::DropHeighest:
		this->DropHeighestDice();
		break;
	case MenuItems::DropLowest:
		this->DropLowestDice();
		break;
	case MenuItems::EndGame:
		this->EndProgram();
		break;
	default:
		break;
	}
}