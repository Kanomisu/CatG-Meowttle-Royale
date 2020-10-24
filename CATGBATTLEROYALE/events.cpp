#include "resources.h"
#include <algorithm>
#include <iostream>
#include <windows.h>

//int backSpace[10] = { 0,2,5,7,10,15,20,50,58,69 };
//int forwardSpace[10] = { 1,3,6,8,11,16,21,51,59,70 };
/*
int restSpace[1] = { 2 };
int fatigueSpace[1] = { 12 };
int gambleSpace[1] = { 4 };
int battleSpace[1] = { 9 };
*/

int backSpace[8] = { 6, 18, 30, 42, 56, 68, 80, 90 };
int forwardSpace[8] = { 2, 12, 24, 36, 48, 60, 72, 84 };
int eventSpace[22] = { 3, 7, 11, 15, 19, 23, 27, 31, 35, 39, 43, 47, 51, 55, 59, 63, 67, 71, 75, 79, 83, 87 };



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
        p_Skipped[p_Cur] = true;
        p_Health[0] = p_S_V[0];
        break;
        ;
    case (1):
        p_Skipped[p_Cur] = true;
        p_Health[1] = p_S_V[1];
        break;
        ;
    case (2):
        p_Skipped[p_Cur] = true;
        p_Health[2] = p_S_V[2];
        break;
        ;
    }
}

void fatigue() {
	switch (p_Cur) {
	case (0):
        p_Skipped[p_Cur] = true;
		break;
		;
	case (1):
        p_Skipped[p_Cur] = true;
		break;
		;
	case (2):
        p_Skipped[p_Cur] = true;
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
    std::cout << "Current Turn: Player " << p_Cur + 1 << "\n" <<
        "Space: " << p_Pos[p_Cur] << "\n" << 
        "HP: " << p_Health[p_Cur] << "/" << p_S_V[p_Cur] << "\n" <<
        "Attack: " << p_S_A[p_Cur] << "\n" << "Resistance: " << p_S_R[p_Cur] << "\n" <<
        "Luck: " << p_S_L[p_Cur] << "\n";
}

int random() {
    return rand() % 5 + 1;
}

int rollAnimation() {
    for (int i = 0; i <= 25; ++i) {
        rNum = random();
        std::system("cls");
        currentBoard();
        std::cout << "\nRoll: ";
        std::cout << rNum;
        Sleep(25);
    }
    return rNum;
}

void checkSpace(int space) {
    if (std::any_of(std::begin(backSpace), std::end(backSpace), [=](int n) {return n == space; })) {

        back();
    }
    else if (std::any_of(std::begin(forwardSpace), std::end(forwardSpace), [=](int n) {return n == space; })) {
        forward();
    }
    else if (std::any_of(std::begin(eventSpace), std::end(eventSpace), [=](int n) {return n == space; })) {
        eventRandomizor();
    }

}