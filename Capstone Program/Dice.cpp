#include "Dice.h"
#include <random>
#include <iostream>
#include <vector>
#include <sstream>


using namespace std;

void Dice::RollDice() {

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

int Dice::GetLandedSide()
{
	return landedSide;
}


Dice::Dice(int side) {
	numberSide = side;
	landedSide = 0;
};

void Dice::ChangeSideNumber(int side) {
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


 DisplayColor::Color Dice::PickSetNextBgMatchColor(int count) const {
	 DisplayColor::Color nextBgColor = bgMatchColor[count%bgMatchColor.size()];
	 this->SetbgColor(nextBgColor);	 
	return nextBgColor;
}


inline void CheckMatches(const DiceVector& dice)
{	 
	int matchCounter = 0;
	for (int i = 0; i < dice.size(); i++)
	{		
		if (dice[i].GetbgColor() == dice[i].defaultColor) {
			int perDieMatchCount = 0;
			for (size_t j = i+1; j < dice.size(); j++)
			{
				if (dice[i] == dice[j]) {
					if (perDieMatchCount == 0)
					{
						dice[i].PickSetNextBgMatchColor(matchCounter);
						matchCounter++;
					}

					perDieMatchCount++;
					dice[j].SetbgColor(dice[i].GetbgColor());
				}
			}
		}
	}
}

inline void CreateDiceDisplayVector(const DiceVector& dice, vector<vector<string>>& output)
{
	for (Dice die : dice)
	{
		string displaylandedSide = to_string(die.GetLandedSide()).size() == 2 ? to_string(die.GetLandedSide()) : " " + to_string(die.GetLandedSide()); //adding space if one diget 
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
