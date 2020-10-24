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
void playerSelect();

int main()
{
	setWindow(110, 40);
	system("Color 0A");
	titleScreen();
	playerSelect();
	playGame();
	return 0;
}

void playGame() {
	bool gameEnd = false;
	int counter = 1;
//	while (!gameEnd) 
	//currentBoard();
	rollAnimation();
//	}



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

void playerSelect()
{
	int selection;
	for (int i = 0; i <= p_Max; i++)
	{
		system("CLS");
		cords(0, 0);
		cout << "Choose thine mighty warrior that you shall fight with, player " << i+1;

		cords(50, 7);
		cout << "Geralt of Meowvia (Atk: 4, Res: 3, HP: 3, Luck: 1)";

		cords(50, 9);
		cout << "Myu, the destroyer (Atk: 3, Res: 2, HP: 4, Luck: 1)";

		cords(50, 11);
		cout << "Beebus the great wizard (Atk: 2, Res: 3, HP: 4, Luck: 1)";

		cin >> selection;

		switch (selection)
		{
		case 1:
			p_S_A[i] = 4;
			p_S_V[i] = 3;
			p_S_R[i] = 3;
			p_S_L[i] = 1;
			p_Max_Health[i] = 3;
			p_Health[i] = 3;
			break;
		case 2:
			p_S_A[i] = 3;
			p_S_V[i] = 4;
			p_S_R[i] = 2;
			p_S_L[i] = 1;
			p_Max_Health[i] = 4;
			p_Health[i] = 4;
			break;
		case 3:
			p_S_A[i] = 2;
			p_S_V[i] = 4;
			p_S_R[i] = 3;
			p_S_L[i] = 1;
			p_Max_Health[i] = 4;
			p_Health[i] = 4;
			break;
		default:
			p_S_A[i] = 100;
			p_S_V[i] = 100;
			p_S_R[i] = 100;
			p_S_L[i] = 100;
			p_Max_Health[i] = 100;
			p_Health[i] = 100;
			break;
		}

	}
}