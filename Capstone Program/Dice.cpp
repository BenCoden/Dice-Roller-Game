#include "Dice.h"
#include <random>
#include <iostream>
#include <vector>
#include <sstream>


using namespace std;

void Dice::rollDice() {

	//Reset Dice
	this -> SetbgColor(defaultColor);
	isVisable = true;

	random_device rd;
	mt19937 gen(rd());

	// Create a distribution for the desired range
	uniform_int_distribution<int> dist(1, numberSide);

	// Generate a random number within the specified range
	landedSide = dist(gen);
}

int Dice::getLandedSide()
{
	return landedSide;
}


Dice::Dice(int side) {
	numberSide = side;
	landedSide = 0;
};

void Dice::changeSideNumber(int side) {
	numberSide = side;
	landedSide = 0;
};


Dice::Dice() {
	numberSide = 2;
	landedSide = 0;
};
void Dice::SetbgColor(DisplayColor::Color newColor) const
{
	bgColor = newColor;
}

DisplayColor::Color Dice::GetbgColor() const
{
	return  bgColor;
}


inline void CheckMatches(const DiceVector& dice)
{
	for (int i = 0; i < dice.size(); i++)
	{		
		if (dice[i].GetbgColor() == dice[i].defaultColor) {
			for (size_t j = i+1; j < dice.size(); j++)
			{
				if (dice[i] == dice[j]) {
					
					dice[i].SetbgColor(DisplayColor::Color::BLUE);
					dice[j].SetbgColor(DisplayColor::Color::BLUE);
				}
			}
		}
	}
}

inline void CreateDiceDisplayVector(const DiceVector& dice, vector<vector<string>>& output)
{
	for (Dice die : dice)
	{
		string displaylandedSide = to_string(die.getLandedSide()).size() == 2 ? to_string(die.getLandedSide()) : " " + to_string(die.getLandedSide()); //adding space if one diget 
		if (die.isVisable) {
			vector<string> dieOutput = {
				"+------+ ",
				"|      | ",
				"|  " + displaylandedSide + "  | ",
				"|      | ",
				"+------+ "
			};
			DisplayColor::CreateStringWithColor(dieOutput, die.GetbgColor());
			output.push_back(dieOutput);
		}
	}
};
inline void PrintDiceVector(vector<vector<string>>& output, ostream& os)
{
	for (int i = 0; i < output[0].size(); i++) {
		for (const vector<string>& dieOutput : output) {
			os << dieOutput[i];
		}
		os << endl;
	}

};
ostream& operator<<(ostream& os, const DiceVector& dice)
{
	vector<vector<string>> output;

	CheckMatches(dice);

	CreateDiceDisplayVector(dice, output);

	PrintDiceVector(output, os);
	os << endl;

	return os;
};
