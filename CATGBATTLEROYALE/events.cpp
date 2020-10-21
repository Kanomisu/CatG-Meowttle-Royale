#include "resources.h"
#include <algorithm>
#include <iostream>
#include <windows.h>

int backSpace[10] = { 0,2,5,7,10,15,20,50,58,69 };
int forwardSpace[10] = { 1,3,6,8,11,16,21,51,59,70 };
int restSpace[1] = { 2 };
int fatigueSpace[1] = { 12 };
int gambleSpace[1] = { 4 };
int battleSpace[1] = { 9 };

int rNum = 0;

//back     1
//forward  2
//rest     3
//fatigue  4
//gamble   5
//battle   6



void eventRandomizor() {
    
}

void back() {
    switch (p_Cur) {
    case (0):
        if (p_Pos[0] >= 3) {
            p_Pos[0] -= 3;
        }
        else {
            p_Pos[0] = 0;
        }
        break;
        ;
    case (1):
        if (p_Pos[1] >= 3) {
            p_Pos[1] -= 3;
        }
        else {
            p_Pos[1] = 0;
        }
        ;
    case (2):
        if (p_Pos[2] >= 3) {
            p_Pos[2] -= 3;
        }
        else {
            p_Pos[2] = 0;
        }
        ;
    }
}

void forward() {
    switch (p_Cur) {
    case (0):
        p_Pos[0] += 3;
        break;
        ;
    case (1):
        p_Pos[1] += 3;
        break;
        ;
    case (2):
        p_Pos[2] += 3;
        break;
        ;
    }
}

void rest() {
    switch (p_Cur) {
    case (0):
        p_1_S = true;
        p_Health[0] = p_Max_Health[0];
        break;
        ;
    case (1):
        p_2_S = true;
        p_Health[1] = p_Max_Health[1];
        break;
        ;
    case (2):
        p_3_S = true;
        p_Health[2] = p_Max_Health[2];
        break;
        ;
    }
}

void fatigue() {
	switch (p_Cur) {
	case (0):
		p_1_S = true;
		break;
		;
	case (1):
		p_2_S = true;
		break;
		;
	case (2):
        p_3_S = true;
        break;
		;
	}
}

void gamble() {

}

void battle() {

}

void sellSoul() {

}

void currentBoard() {
    //display whatever

    //Player: 1/2/3
    //Space: X
    //Stats: 
        //Health:
        //Strength:
        //Vitatlity:
        //Luck::
        //Etc.
}

int random() {
    return rand() % 5 + 1;
}

void rollAnimation() {
    for (int i = 0; i <= 25; ++i) {
        rNum = random();
        std::system("cls");
        currentBoard();
        std::cout << "\nRoll: ";
        std::cout << rNum;
        Sleep(25);
    }
}

void checkSpace(int space) {
    if (std::any_of(std::begin(backSpace), std::end(backSpace), [=](int n) {return n == space;})) {
        back();
    }
    else if (std::any_of(std::begin(forwardSpace), std::end(forwardSpace), [=](int n) {return n == space;})) {
        forward();
    }
    else if (std::any_of(std::begin(restSpace), std::end(restSpace), [=](int n) {return n == space;})) {
        rest();
    }
    else if (std::any_of(std::begin(fatigueSpace), std::end(fatigueSpace), [=](int n) {return n == space;})) {
        fatigue();
    }
    else if (std::any_of(std::begin(gambleSpace), std::end(gambleSpace), [=](int n) {return n == space;})) {
        gamble();
    }
    else if (std::any_of(std::begin(battleSpace), std::end(battleSpace), [=](int n) {return n == space;})) {
        battle();
    }
}