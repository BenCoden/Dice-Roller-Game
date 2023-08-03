#pragma once
class GameBase
{

public:
protected:
	bool validateInput(int , int );
	bool gameOver = false;
virtual bool isGameOver() = 0;

};

