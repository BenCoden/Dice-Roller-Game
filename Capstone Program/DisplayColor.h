#pragma once

#include <vector>
#include <string>

using namespace std;

class  DisplayColor
{
public:
	static enum class Color {
		RESET,
		BLACK,
		RED,
		GREEN,
		YELLOW,
		BLUE,
		MAGENTA,
		CYAN,
		WHITE
	};

	static void PrintWithColor(const string&, Color);
	static void CreateStringWithColor( vector<string>&, Color);
	


private:
	static string GetAnsiColorCode(Color );
};

