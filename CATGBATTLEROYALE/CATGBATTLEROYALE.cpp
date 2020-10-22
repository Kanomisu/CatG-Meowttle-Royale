#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "resources.h"

using namespace std;

/*
This is our game for our first GDW project!
CATG Battle royale s textbased and in one file
Date: 10/20/2020
Authors: Ricardo Prato, Ryan Dinh, Timothy Loudon, Nathan Tyborski, Kieran Lockyer
*/

void setWindow(int, int);
void playGame();

int main()
{
	setWindow(110, 40);
	system("Color 0A");
	menu();
	//playGame();
	return 0;
}

void playGame() {
//	int playerPoints[5];
//	bool gameEnd = false;

//	while (!gameEnd) {

//	}


	rollAnimation();

}

void setWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT side;
	side.Top = 0;
	side.Left = 0;
	side.Bottom = Height;
	side.Right = Width;

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(console, coord); //Buffer size
	SetConsoleWindowInfo(console, TRUE, &side); // Window size
}

void roll() {

}

void turnStart() {
	switch(p_Cur) {
		case (0):
			if (p_1_S) {
				//player has been skipped
				p_1_S = false;
				endTurn();
				break;
			}
			else {
				roll();
				break;
			}
			;
		case (1):
			if (p_2_S) {
				//player has been skipped
				p_2_S = false;
				endTurn();
				break;
			}
			else {
				roll();
				break;
			}
			;
		case (2):
			if (p_3_S) {
				//player has been skipped
				p_3_S = false;
				endTurn();
				break;
			}
			else {
				roll();
				break;
			}
			;
	}
}

void endTurn() {
	if (p_Cur >= p_Max) {
		p_Cur = 0;
	}
	else {
		p_Cur += 1;
	}
}
