#pragma once
class GameBase
{

public:
protected:
	bool ValidateInput(int , int );
	bool gameOver = false;
virtual bool IsGameOver() = 0;

};

