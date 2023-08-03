#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include "DisplayColor.h"


using namespace std;
class DiceVector;

class Dice
{
	const vector<DisplayColor::Color> bgMatchColor { 
				DisplayColor::Color::BLUE,
					DisplayColor::Color::MAGENTA,
					DisplayColor::Color::YELLOW
	};
	mutable  DisplayColor::Color bgColor = defaultColor;
	int numberSide;
	int landedSide;
public:


	const DisplayColor::Color defaultColor = DisplayColor::Color::CYAN;


	bool operator==(const Dice& other) const
	{
		return (landedSide == other.landedSide && isVisable && other.isVisable);
	}

	bool isVisable = true;
	
	Dice();
	Dice(int);
	void SetbgColor(DisplayColor::Color) const;
	DisplayColor::Color GetbgColor() const;
	DisplayColor::Color PickSetNextBgMatchColor(int) const;
	void RollDice();
	int GetLandedSide();
	void ChangeSideNumber(int);
};

void CheckMatches(const DiceVector& dice);

ostream& operator<<(ostream& os, const DiceVector& dice);


class DiceVector : public std::vector<Dice>
{
public:
	int isVisableSize() const
	{
		int count = 0;
		for (const Dice& die : *this)
		{
			if (die.isVisable)
				count++;
		}
		return count;
	}
};
