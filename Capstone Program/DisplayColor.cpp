#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "DisplayColor.h"

void DisplayColor::PrintWithColor(const std::string& text, Color color)
{
	std::string ansiColorCode = GetAnsiColorCode(color);
	std::cout << ansiColorCode << text << "\033[0m";
}

void DisplayColor::CreateStringWithColor(vector<string>& text, Color color)
{
	std::string ansiColorCode = GetAnsiColorCode(color);
	for (string& s : text)
	{
		s = ansiColorCode + s + "\033[0m";
	};
	
}

std::string DisplayColor::GetAnsiColorCode(Color color)
{
	switch (color)
	{
	case Color::RESET:   return "\033[0m";
	case Color::RED:     return "\033[31m";
	case Color::GREEN:   return "\033[32m";
	case Color::YELLOW:  return "\033[33m";
	case Color::BLUE:    return "\033[34m";
	case Color::MAGENTA: return "\033[35m";
	case Color::CYAN:    return "\033[36m";
	default:             return "\033[0m";
	}
}