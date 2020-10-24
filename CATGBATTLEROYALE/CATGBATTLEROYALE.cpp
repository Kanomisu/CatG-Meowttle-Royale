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
	//while (!gameEnd)
	//{
		//turnStart();
		//move();
		//checkIfLandedOnSpace();
		//doEvent();
	//}



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
	int amtMove;
	amtMove = rollAnimation();
	cout << "You rolled a " << amtMove << endl;
	p_Pos[p_Cur] += amtMove;
	cout << "Player " << p_Cur + 1 << " is now at " << p_Pos;
}

void turnStart() {
	if (p_Skipped[p_Cur] == true) {
		p_Skipped[p_Cur] = false;
		endTurn();
	}
	
}

void endTurn() {
	if (p_Cur >= p_Max) {
		p_Cur = 0;
	}
	else {
		p_Cur ++;
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
		cout << "1. Geralt of Meowvia (Atk: 4, Res: 3, HP: 3, Luck: 1)";

		cords(50, 9);
		cout << "2. Myu, the destroyer (Atk: 3, Res: 2, HP: 4, Luck: 1)";

		cords(50, 11);
		cout << "3. Beebus the great wizard (Atk: 2, Res: 3, HP: 4, Luck: 1)\n\n";

		cin >> selection;

		switch (selection)
		{
		case 1:
			p_S_A[i] = 4;
			p_S_V[i] = 3;
			p_S_R[i] = 3;
			p_S_L[i] = 1;
			p_Health[i] = 3;
			p_S_V[i] = 3;
			break;
		case 2:
			p_S_A[i] = 3;
			p_S_V[i] = 4;
			p_S_R[i] = 2;
			p_S_L[i] = 1;
			p_Health[i] = 3;
			p_S_V[i] = 3;
			break;
		case 3:
			p_S_A[i] = 2;
			p_S_V[i] = 4;
			p_S_R[i] = 3;
			p_S_L[i] = 1;
			p_Health[i] = 3;
			p_S_V[i] = 3;
			break;
		default:
			p_S_A[i] = 100;
			p_S_V[i] = 100;
			p_S_R[i] = 100;
			p_S_L[i] = 100;
			p_Health[i] = 3;
			p_S_V[i] = 3;
			break;
		}

	}
}