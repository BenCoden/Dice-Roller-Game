#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include "DisplayColor.h"


using namespace std;
class DiceVector;

class Dice
{
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
	void rollDice();
	int getLandedSide();
	void changeSideNumber(int);
};

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
