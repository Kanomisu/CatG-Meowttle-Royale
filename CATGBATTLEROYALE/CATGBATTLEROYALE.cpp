#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "resources.h"
#include <conio.h>
#include <ctime>
#include <stdlib.h> 
using namespace std;

/*
This is our game for our first GDW project!
CATG Battle royale is textbased rpg!
Date: 10/20/2020
Authors: Ricardo Prato, Ryan Dinh, Timothy Loudon, Nathan Tyborski, Kieran Lockyer
*/

void setWindow(int, int);
void playGame();
void playerSelect();
void roll();
void turnStart();
bool checkToEndGame();
void endGame();
void checkIfFinished();

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
	while (!gameEnd)
	{
		turnStart();
 		if (!p_Skipped[p_Cur])
		{
			roll();
			checkSpace(p_Pos[p_Cur]);
		}
		endTurn();
		gameEnd = checkToEndGame();
	}
	endGame();



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
	int time_seed = time(NULL);
	srand(time_seed);
	std::cout << "Press any button to roll!!!";
	int input = _getch();
	if (input == 0xE0)
	{
		input = _getch();
	}

	amtMove = rollAnimation();
	cout << "\nYou rolled a " << amtMove << endl;
	p_Pos[p_Cur] += amtMove;
	checkIfFinished();
	Sleep(25);
	cout << "Player " << p_Cur + 1 << " is now at space " << p_Pos[p_Cur] << endl;
}

void checkIfFinished() 
{
	if (p_Pos[p_Cur] >= 91)
	{
		p_Pos[p_Cur] = 91;
		cout << "Congratulations, you have completed the board!!!\n";
		cout << "This game shall now come to a close...\n";
		p_Finished[p_Cur] = true;
	}
}

void turnStart() {
	if (p_Skipped[p_Cur]){
		//player has been skipped
		//p_Skipped[p_Cur] = false;
		//endTurn();
		cout << "Player " << p_Cur + 1 << "'s has been skipped, proceeding to the next player...";
	}
	else if (p_Finished[p_Cur]) 
	{
		cout << "Player " << p_Cur + 1 << " has finsihed the board, proceeding to the next player...";
	}
	else {
		//roll();
		currentBoard();
	}
	sellSoul(); //checks if we should ask to sell soul
}

void endTurn() {
	cout << "Press any button to end your turn:\n";
	if (p_Skipped[p_Cur] == true) {
		if (skipCount[p_Cur] == 0) {
			skipCount[p_Cur]++;
		}
		else {
			skipCount[p_Cur] = 0;
			p_Skipped[p_Cur] = false;
		}
	}
	int input = _getch();
	if (input == 0xE0)
	{
		input = _getch();
	}
	std::system("cls");
	if (p_Cur >= p_Max) {
		p_Cur = 0;
	}
	else {
		p_Cur ++;
	}
}

bool checkToEndGame()
{
	if (p_Finished[0] || p_Finished[1] || p_Finished[2])
	{
		return true;
	}
	else
	{
		return false;
	}
}

void endGame()
{
	std::system("cls");
	int totalStats[3] = { 0, 0, 0 };
	cout << "And with that, our jounrey comes to an end!\n Let us see how well you all performed...\n";
	for (int i = 0; i <= p_Max; i++)
	{
		Sleep(3000);
		totalStats[i] = player(i);
	}

	if (totalStats[0] > totalStats[1])
	{
		if (totalStats[0] > totalStats[2]) 
		{
			if (totalStats[1] > totalStats[2])
			{
				cout << "Player 1 Wins!\nPlayer 2 is in second!\nPlayer 3 came in last."; 
			}
			else 
			{ 
				cout << "Player 1 Wins!\nPlayer 3 is in seccond!\nPlayer 2 came in last."; 
			}
		}

		else if (totalStats[0] < totalStats[2])
		{
			if (totalStats[0] > totalStats[1]) 
			{ 
				cout << "Player 3 Wins!\nPlayer 1 is in second!\nPlayer 2 came in last."; 
			}
			else 
			{
				cout << "Player 3 Wins!\nPlayer 2 is in seccond!\nPlayer 1 came in last."; 
			}
		}
	}

	if (totalStats[1] > totalStats[0])
	{
		if (totalStats[1] > totalStats[2])
		{
			if (totalStats[0] > totalStats[2]) 
			{ 
				cout << "Player 2 Wins!\nPlayer 1 is in second!\nPlayer 3 came in last."; 
			}
			else 
			{ 
				cout << "Player 2 Wins!\nPlayer 3 is in seccond!\nPlayer 1 came in last."; 
			}

		}
		else if (totalStats[0] < totalStats[2])
		{
			if (totalStats[0] > totalStats[1])
			{
				cout << "Player 3 Wins!\nPlayer 1 is in second!\nPlayer 2 came in last.";
			}
			else
			{
				cout << "Player 3 Wins!\nPlayer 2 is in seccond!\nPlayer 1 came in last.";
			}
		}
	}
}

void playerSelect()
{
	int selection = 0;
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
			break;
		case 2:
			p_S_A[i] = 3;
			p_S_V[i] = 4;
			p_S_R[i] = 2;
			p_S_L[i] = 1;
			p_Health[i] = 4;
			break;
		case 3:
			p_S_A[i] = 2;
			p_S_V[i] = 4;
			p_S_R[i] = 3;
			p_S_L[i] = 1;
			p_Health[i] = 4;
			break;
		default:
			p_S_A[i] = 1;
			p_S_V[i] = 1;
			p_S_R[i] = 1;
			p_S_L[i] = 1;
			p_Health[i] = 1;
			cout << "Hey kid, you can't be inputting numbers that aren't allowed, input 1-3 next time!!!!!\n";
			Sleep(5000);
			i--;
			break;
		}

	}
	system("cls");
}