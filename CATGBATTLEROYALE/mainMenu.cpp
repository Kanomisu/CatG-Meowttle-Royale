#include "resources.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //get console so you can use it in cords

void help();
void story();
void credits();
void cords(int, int);


void titleScreen() {
	std::cout <<
		" " << endl << " " << endl << " " << endl << " " << endl <<
		" " << endl << " " << endl << " " << endl << " " << endl <<
		"\t\t\t\t     _________  ____________                " << endl <<
		"\t\t\t\t    / ____/   |/_  __/ ____/                " << endl <<
		"\t\t\t\t   / /   / /| | / / / / __(_)               " << endl <<
		"\t\t\t\t  / /___/ ___ |/ / / /_/ /                  " << endl <<
		"\t\t\t\t  \\____/_/  |_/_/__\\____(_)____    ______   " << endl <<
		"\t\t\t\t     / __ )/   |/_  __/_  __/ /   / ____/   " << endl <<
		"\t\t\t\t    / __  / /| | / /   / / / /   / __/      " << endl <<
		"\t\t\t\t   / /_/ / ___ |/ /   / / / /___/ /___      " << endl <<
		"\t\t\t\t  /_____/_/ _|_/_/  _/_/_/_____/_____/___   " << endl <<
		"\t\t\t\t     / __ \\/ __ \\ \\/ /   |  / /   / ____/   " << endl <<
		"\t\t\t\t    / /_/ / / / /\\  / /| | / /   / __/      " << endl <<
		"\t\t\t\t   / _, _/ /_/ / / / ___ |/ /___/ /___      " << endl <<
		"\t\t\t\t  /_/ |_|\\____/ /_/_/  |_/_____/_____/      " << endl;

	cords(38, 28);
	std::cout << "Press any button to continue!";
	int input = _getch();
	if (input == 0xE0)
	{
		input = _getch();
	}
	menu();
}

void menu()
{
	char input = '0';
	int y = 2; //set y to be at 2 and add it to actual y value, HOVERS OVER HOW TO PLAY ON STARTUP
	bool running = true; //while in menu/game keep as true, false terminates
	system("CLS");

	while (running) //while the menu is running
	{
		std::cout <<
			"                   /\\					\n" <<
			"                  /  \\					\n" <<
			"                 / /\\ \\					\n" <<
			"                / /  \\ \\					\n" <<
			"               / /    \\ \\				\n" <<
			"              /_/      \\_\\				\n" <<
			"              \\    '`    /				\n" <<
			"               )   ||   (				\n" <<
			"               |   ||   |				\n" <<
			"               |   ||   |				\n" <<
			"               |   ||   |				\n" <<
			"               |   ||   |				\n" <<
			"               |   ||   |				\n" <<
			"               |   ||   |				\n" <<
			"               |   ||   |				\n" <<
			"               |   ||   |				\n" <<
			"               |   ||   |				\n" <<
			"   /           |   ||   |           \\	\n" <<
			"  /(           |   ||   |           )\\	\n" <<
			"  |`\\_         |   ||   |         _/'|	\n" <<
			"  |`. `-._     |   ||   |     _,-' ,'|	\n" <<
			"  (   ` . `-._ |  _--_  | _,-' , '   )	\n" <<
			"   `.._   ` . `-./.__.\\.-' , '   _,-'	\n" <<
			"       `-._   ` | /  \\ | '   _,-'		\n" <<
			"           `-._/ |_()_| \\_,-'			\n" <<
			"        ___.-'   ______   `-,			\n" <<
			"       '-----.  |______|   /				\n" <<
			"              \\  ______   /				\n" <<
			"              |  \\>  </  /				\n" <<
			"               \\________/				\n" <<
			"               _]______[_				\n" <<
			"               |        |				\n" <<
			"               |________|				\n" <<
			"                ]______[					\n" <<
			"               |        |				\n" <<
			"               |________|				\n" <<
			"                 ]____[					\n" <<
			"               .'      `.				\n" <<
			"               |        |				\n" <<
			"               |        |				\n" <<
			"                `.____.'					  ";

		cords(49, 25);
		std::cout <<
			"                 ________________\n";
		cords(49, 26);
		std::cout <<
			"                |                |_____    __\n";
		cords(49, 27);
		std::cout <<
			"                |  To Conquest!  |     |__|  |_________\n";
		cords(49, 28);
		std::cout <<
			"                |________________|     |::|  |        /\n";
		cords(49, 29);
		std::cout <<
			"   /\\**/\\       |                \\.____|::|__|      <\n";
		cords(49, 30);
		std::cout <<
			"  ( o_o  )_     |                      \\::/  \\._______\\\n";
		cords(49, 31);
		std::cout <<
			"   (u--u   \\_)  |\n";
		cords(49, 32);
		std::cout <<
			"    (||___   )==\\\n";
		cords(49, 33);
		std::cout <<
			"  ,dP' / b /= (/ P'/b\\\n";
		cords(49, 34);
		std::cout <<
			"  |8 || 8\\=== || 8\n";
		cords(49, 35);
		std::cout <<
			"  `b,  ,P  `b,  ,P\n";

		cords(50, 7);
		std::cout << "Main Menu";
		cords(45, 8);
		std::cout << "___________________";

		cords(48, 11);
		std::cout << "1) Play Game";
		cords(48, 13);
		std::cout << "2) How to Play";
		cords(48, 15);
		std::cout << "3) Story";
		cords(48, 17);
		std::cout << "4) Credits";
		cords(48, 19);
		std::cout << "5) Exit Game";

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
				if (y < 8)
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
			{
				running = false; //ends menu
			}
			system("CLS");
			input = ' ';
		}

		if (y == 2)
		{
			help();
		}
		
		if (y == 4)
		{
			story();
		}

		if (y == 6)
		{
			credits();
		}

		if (y == 8)
		{
			exit(0);
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
	system("CLS");

	cords(20, 3);
	std::cout << "\t   Obey the Rules!";
	cords(20, 4);
	std::cout << "\t_____________________";
	cords(4, 7);
	std::cout <<
		"1. Players will each take turns picking their mighty warrior.";
	cords(4, 9);
	std::cout <<
		"2. Players will begin at the first space and take turns rolling respectively.";
	cords(4, 11);
	std::cout <<
		"3. Players will encounter event panels that will determine their \n       fortune or misfortune.";
	cords(4, 14);
	std::cout <<
		"4. Raise your stats through battles and events throughout \n       the course of the game!";
	cords(4, 17);
	std::cout <<
		"5. If your HP hits 0, you lose a turn but gain full HP the next.";
	cords(4, 19);
	std::cout <<
		"6. Your goal will be to make it out with the most stats at the end.";
	cords(4, 21);
	std::cout <<
		"7. All players adventures will end once someone reaches the end of the board!";
	cords(4, 23);
	std::cout <<
		"8. Remember to have fun!!";

	cords(80, 4);
	std::cout <<
		"   |\\                     /)	\n";
	cords(80, 5);
	std::cout <<
		" /\\_\\\\__               (_//	\n";
	cords(80, 6);
	std::cout <<
	"|   `>\\-`     _._       //`)	\n";
	cords(80, 7);
	std::cout <<
	" \\ /` \\\\  _.-`:::`-._  //		\n";
	cords(80, 8);
	std::cout <<
	"  `    \\|`    :::    `|/		\n";
	cords(80, 9);
	std::cout <<
	"        |     :::     |		\n";
	cords(80, 10);
	std::cout <<
	"        |.....:::.....|		\n";
	cords(80, 11);
	std::cout <<
	"        |:::::::::::::|		\n";
	cords(80, 12);
	std::cout <<
	"        |     :::     |		\n";
	cords(80, 13);
	std::cout <<
	"        \\     :::     /		\n";
	cords(80, 14);
	std::cout <<
	"	 \\    :::    /			\n";
	cords(80, 15);
	std::cout <<
	"          `-. ::: .-'			\n";
	cords(80, 16);
	std::cout <<
	"           //`:::`\\\\			\n";
	cords(80, 17);
	std::cout <<
	"          //   '   \\\\			\n";
	cords(80, 18);
	std::cout <<
		"         |/         \\\\";	

	cords(80, 28);
	std::cout << "BACK";
	while (input != char(13))
	{
		cords(75, 26 + y);
		std::cout << "->";
		cords(0, 0);
		input = _getch();
		cords(75, 26 + y);
		std::cout << "  ";
	}
}

void story() //displays how to play
{
	char input = '0';
	int y = 2;
	system("CLS");
	std::cout << 
		"\n\n" << 
		"\tOnce upon a time long ago, in a land far far away, there once was a tribe of Cat people who\n" <<
		"\tlead a great civilization known as Meowvia. They were all blessed with great power, wealth, and\n" <<
		"\tled by their king, Adam Nyandler. The world always seemed to be perfect with its fulfilling and\n" <<
		"\trich lands full of milk, honey, and all the catnip they could ever imagine... but one day these\n" <<
		"\tblessed lands were cursed with devilish creatures known as Slimes. These slimes first seemed\n" <<
		"\tharmless to those common to the lands, however they began to raid and consume the catnip\n" <<
		"\tfields that the cats relied upon and started becoming more and more powerful, growing to be a\n" <<
		"\tmuch more dangerous threat than the people could have imagined them to be. The king and his\n" <<
		"\tinfinite wisdom knew that they would be a threat to the future of his cat people, so being all\n" <<
		"\tknowing, he hatched a plan to destroy these wicked beasts one and for all. He would send 3 of\n" <<
		"\tthe most mighty warriors out to fight the slimes, and the one who proved the most powerful\n" <<
		"\twould be given any wish he wanted. And so he gathered up the three most powerful warriors,\n" <<
		"\tsending them off on their quest to destroy their foes, claim glory for their people, and to become\n" << 
		"\tfar more powerful than what they could have ever comprehended before… \n\n" <<
		"\tThis is the world of the cats, and now it's their time to reclaim what's theirs.";
	
	cords(10, 25);
	std::cout <<
		"                 /\\\n";
	cords(10, 26);
	std::cout <<
		"                /  |\n";
	cords(10, 27);
	std::cout <<
		"  *            /  /________________________________________________\n";
	cords(10, 28);
	std::cout <<
		" (O)77777777777)  7                                                `~~--__\n";
	cords(10, 29);
	std::cout <<
		"8OO>>>>>>>>>>>>] <===========================================>          __-\n";
	cords(10, 30);
	std::cout <<
		" (O)LLLLLLLLLLL)  L________________________________________________.--~~\n";
	cords(10, 31);
	std::cout <<
		"  *            \\  \\\n";
	cords(10, 32);
	std::cout <<
		"                \\  |";
	cords(10, 33);
	std::cout <<
		"                 \\/";

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
	}
}

void credits()
{
	system("CLS");
	char input = ' ';
	cords(50, 7);
	std::cout << "CREDITS";
	cords(45, 8);
	std::cout << "_________________";
	cords(42, 11);
	std::cout << "Ricardo Prato (100787893)";
	cords(42, 13);
	std::cout << "Ryan Dinh (100804962)";
	cords(42, 15);
	std::cout << "Kieran Lockyer (100790402)";
	cords(42, 17);
	std::cout << "Nathan Tyborski (100781410)";
	cords(42, 19);
	std::cout << "Timothy Loudon (100791672)";

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