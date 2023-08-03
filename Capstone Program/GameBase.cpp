#include "GameBase.h"
#include <iostream>
#include "DisplayColor.h"

using namespace std;

bool GameBase::ValidateInput(int input, int max) {

	if (cin.fail() || !(input > 0 && input < max + 1)) {

		DisplayColor::PrintWithColor("Invalid input.", DisplayColor::Color::RED);
		cout << endl;
		
		cout << "Please enter a valid integer between 1 and " + to_string(max) + "."<< endl;

		cin.clear();

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return false;
	}

	return true;
}


