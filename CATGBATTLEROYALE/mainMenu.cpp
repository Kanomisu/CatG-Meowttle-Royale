#include "resources.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //get console so you can use it in cords

void help();
void credits();
void cords(int, int);

void menu()
{
	char input = '0';
	int y = 2; //set y to be at 2 and add it to actual y value, HOVERS OVER HOW TO PLAY ON STARTUP
	bool running = true; //while in menu/game keep as true, false terminates
	system("CLS");

	while (running) //while the menu is running
	{

		//replace this with catg meowttle royale text later
		cords(50, 7);
		std::cout << "Main Menu";
		//replace this with catg meowttle royale text later

		cords(50, 11);
		std::cout << "1) Play Game";
		cords(50, 13);
		std::cout << "2) How to Play";
		cords(50, 15);
		std::cout << "3) Exit Game";

		while (input != char(13)) //when you havent hit enter
		{
			cords(45, 11 + y);
			std::cout << "->"; //cursor
			cords(0, 0); //puts the underscore at top left
			input = _getch();
			cords(45, 11 + y);
			std::cout << "  ";

			if (input == 's')
			{
				if (y < 4)
				{
					y += 2;
				}
			}

			if (input == 'w')
			{
				if (y > 0)
				{
					y -= 2;
				}
			}
		}

		if (y == 0) //first item on menu
		{
			//start game
		}

		if (y == 2)
		{
			help();
		}
		/*
		if (y == 4)
		{
			Settings();   //Maybe add settings on menu to set variables, etc.
		}
		*/
		if (y == 4)
		{
			running = false; //ends menu
		}
		system("CLS");
		y = 2;
		input = ' ';
	}
}

void help() //displays how to play
{
	char input = '0';
	int y = 2;
	while (input != ' ')
	{
		system("CLS");
		std::cout << "blahblahblahblahblahblahblahblahblahblahblahblahblahblahblahblahblahblah";
		cords(80, 20);
		std::cout << "CREDITS";
		cords(80, 22);
		std::cout << "BACK";
		while (input != char(13))
		{
			cords(75, 20 + y);
			std::cout << "->";
			cords(0, 0);
			input = _getch();
			cords(75, 20 + y);
			std::cout << "  ";
			if (input == 's')
			{
				if (y < 2)
				{
					y += 2;
				}
			}

			if (input == 'w')
			{
				if (y > 0)
				{
					y -= 2;
				}
			}
		}
		
		if (y == 0)
		{
			credits();
			input = '0';
		}

		if (y == 2)
		{
			input = ' ';
		}
		system("CLS");
		y = 2;
	}
}

void credits()
{
	system("CLS");
	char input = ' ';
	cords(50, 7);
	std::cout << "CREDITS";
	cords(45, 8);
	std::cout << "-----------------";
	cords(42, 11);
	std::cout << "Ricardo Prato (100787893)";
	cords(42, 13);
	std::cout << "Ryan Dinh (100804962)";
	cords(42, 15);
	std::cout << "Timothy Loudon (100791672)";
	cords(42, 17);
	std::cout << "Nathan Tyborski (100781410)";
	cords(42, 19);
	std::cout << "Kieran Lockyer (100790402)";

	cords(80, 22);
	std::cout << "BACK";
	while (input != char(13))
	{
		cords(75, 22);
		std::cout << "->";
		cords(0, 0);
		input = _getch();
		cords(75, 22);
		std::cout << "  ";
	}
}

void cords(int x, int y)
{
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(console, position);
}