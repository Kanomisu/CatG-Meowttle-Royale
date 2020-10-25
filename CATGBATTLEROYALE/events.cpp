#include "resources.h"
#include <algorithm>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

int backSpace[10] = { 0,2,5,7,10,15,20,50,58,69 };
int forwardSpace[10] = { 1,3,6,8,11,16,21,51,59,70 };
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


int random() {
    return rand() % 5 + 1;
}


void eventRandomizor() {
    rNum = rand() % 6;
    switch(rNum) {
    case(0):
        back();
        break;
        ;
    case(1):
        forward();
        break;
        ;
    case(2):
        rest();
        break;
        ;
    case(3):
        fatigue();
        break;
        ;
    case(4):
        battle();
        break;
        ;
    case(5):
        gamble();
        break;
        ;
    }
}

void back() {
    if (p_Pos[p_Cur] >= 3) {
        p_Pos[p_Cur] -= 3;
    }
    else {
        p_Pos[p_Cur] = 0;
    }
}

void forward() {
    p_Pos[p_Cur] += 3;
}

void rest() {
    p_Skipped[p_Cur] = true;
    p_S_V[p_Cur] = p_Max_Health[p_Cur];
}

void fatigue() {
    p_Skipped[p_Cur] = true;
}

void gamble() {
    system("CLS");
    currentBoard();
    std::cout << "Pick a stat you would like to improve. \n 1. Attack \n2. Vitality \n3. Resistance \n4. Luck\n";
    std::cin >> response;
    std::cout << "\nPick 1 or 2\n";
    std::cin >> gamNum;
    rNum = rand() % 2 + 1;
    if (rNum == gamNum) {
        switch (response) {
        case(1):
            p_S_A[p_Cur] += 1;
            break;
            ;
        case(2):
            p_S_V[p_Cur] += 1;
            break;
            ;
        case(3):
            p_S_R[p_Cur] += 1;
            break;
            ;
        case(4):
            p_S_L[p_Cur] -= 1;
            break;
            ;
        }
    }
    else {
        switch (response) {
        case(1):
            p_S_A[p_Cur] -= 1;
            break;
            ;
        case(2):
            p_S_V[p_Cur] -= 1;
            break;
            ;
        case(3):
            p_S_R[p_Cur] -= 1;
            break;
            ;
        case(4):
            p_S_L[p_Cur] -= 1;
            break;
            ;
        }
    }
}

void battle() {
    system("CLS");
    currentBoard();
    std::cout << "\n\nYou came across some sort of creature!\n\nWhat would you like to do?\n1. Fight \n2. Flee\n";
    std::cin >> response;
    if (response == 1) {
        if (p_SellSoul[p_Cur] == 1) {

        }
        else {

        }
    }
    else {
        std::cout << "\n\nYou cowarded behind a rock...";
    }
}

void sellSoul() {
    if (!ranSellSoul) {
        if (p_Pos[0] >= 45 && p_Pos[1] >= 45 && p_Pos[2] >= 45) {
            if (p_Cur == 0) {
                if (p_Pos[0] < p_Pos[1] && p_Pos[0] < p_Pos[2]) {
                    ranSellSoul = true;
                    soulDia();
                }
            }
            else if (p_Cur == 1) {
                if (p_Pos[1] < p_Pos[0] && p_Pos[1] < p_Pos[2]) {
                    ranSellSoul = true;
                    soulDia();
                }
            }
            else if (p_Cur == 2) {
                if (p_Pos[2] < p_Pos[0] && p_Pos[2] < p_Pos[1]) {
                    ranSellSoul = true;
                    soulDia();
                }
            }
        }
    }
}

void soulDia() {
    system("CLS");
    std::cout << "\n\n[DEVIL] Hello there player " << p_Cur + 1 << " it seems like you are in need of help... How about I propose an offer you can't resist! If you are able to correctly guess an opponent's number you shall receive half of the other players stats in exchange for doubling any negative actions that happen to you.\n\n 1. Yes \n 2. No";
    std::cin >> response;
    if (response == 1) {
        p_SellSoul[p_Cur] = 1;
        system("CLS");
        std::cout << "Player 1 please input a number\n";
        std::cin >> pickedNum[0];
        system("CLS");
        std::cout << "Player 2 please input a number\n";
        std::cin >> pickedNum[1];
        system("CLS");
        std::cout << "Player 3 please input a number\n";
        std::cin >> pickedNum[2];

        if (p_Cur == 0) {
            if (pickedNum[0] == pickedNum[1] || pickedNum[0] == pickedNum[2]) {
                std::cout << "Player 1 has successfully guessed the correct number!";
                p_S_A[0] += (p_S_A[1] / 2);
                p_S_A[1] = (p_S_A[1] / 2);

                p_S_A[0] += (p_S_A[2] / 2);
                p_S_A[2] = (p_S_A[2] / 2);


                p_S_V[0] += (p_S_V[1] / 2);
                p_S_V[1] = (p_S_V[1] / 2);

                p_S_V[0] += (p_S_V[2] / 2);
                p_S_V[2] = (p_S_V[2] / 2);


                p_S_R[0] += (p_S_R[1] / 2);
                p_S_R[1] = (p_S_R[1] / 2);

                p_S_R[0] += (p_S_R[2] / 2);
                p_S_R[2] = (p_S_R[2] / 2);


                p_S_L[0] += (p_S_L[1] / 2);
                p_S_L[1] = (p_S_L[1] / 2);

                p_S_L[0] += (p_S_L[2] / 2);
                p_S_L[2] = (p_S_L[2] / 2);
            }
            else {
                std::cout << "Player 1 has failed to guess the correct number!";
            }
        }
        else if (p_Cur == 1) {
            if (pickedNum[1] == pickedNum[0] || pickedNum[1] == pickedNum[2]) {
                std::cout << "Player 1 has successfully guessed the correct number!";
                p_S_A[1] += (p_S_A[0] / 2);
                p_S_A[0] = (p_S_A[0] / 2);

                p_S_A[1] += (p_S_A[2] / 2);
                p_S_A[2] = (p_S_A[2] / 2);


                p_S_V[1] += (p_S_V[0] / 2);
                p_S_V[0] = (p_S_V[0] / 2);

                p_S_V[1] += (p_S_V[2] / 2);
                p_S_V[2] = (p_S_V[2] / 2);


                p_S_R[1] += (p_S_R[0] / 2);
                p_S_R[0] = (p_S_R[0] / 2);

                p_S_R[1] += (p_S_R[2] / 2);
                p_S_R[2] = (p_S_R[2] / 2);


                p_S_L[1] += (p_S_L[0] / 2);
                p_S_L[0] = (p_S_L[0] / 2);

                p_S_L[1] += (p_S_L[2] / 2);
                p_S_L[2] = (p_S_L[2] / 2);
            }
            else {
                std::cout << "Player 2 has failed to guess the correct number!";
            }
        }
        else if (p_Cur == 2) {
            if (pickedNum[2] == pickedNum[0] || pickedNum[2] == pickedNum[1]) {
                std::cout << "Player 1 has successfully guessed the correct number!";
                p_S_A[2] += (p_S_A[1] / 2);
                p_S_A[1] = (p_S_A[1] / 2);

                p_S_A[2] += (p_S_A[0] / 2);
                p_S_A[0] = (p_S_A[0] / 2);


                p_S_V[2] += (p_S_V[1] / 2);
                p_S_V[1] = (p_S_V[1] / 2);

                p_S_V[2] += (p_S_V[0] / 2);
                p_S_V[0] = (p_S_V[0] / 2);


                p_S_R[2] += (p_S_R[1] / 2);
                p_S_R[1] = (p_S_R[1] / 2);

                p_S_R[2] += (p_S_R[0] / 2);
                p_S_R[0] = (p_S_R[0] / 2);


                p_S_L[2] += (p_S_L[1] / 2);
                p_S_L[1] = (p_S_L[1] / 2);

                p_S_L[2] += (p_S_L[0] / 2);
                p_S_L[0] = (p_S_L[0] / 2);
            }
            else {
                std::cout << "Player 3 has failed to guess the correct number!";
            }
        }

    }
    else {
        std::cout << "[DEVIL] You will regret not taking my deal!";
    }
}

void currentBoard() {
    std::cout << "Current Turn: Player " << p_Cur + 1 << "\n" <<
        "Space: " << p_Pos[p_Cur] << "\n" << 
        "HP: " << p_Health[p_Cur] << "/" << p_S_V[p_Cur] << "\n" <<
        "Attack: " << p_S_A[p_Cur] << "\n" << "Resistance: " << p_S_R[p_Cur] << "\n" <<
        "Luck: " << p_S_L[p_Cur] << "\n";
}

int rollAnimation() {
    for (int i = 0; i <= 20; ++i) {
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
    else if (std::any_of(std::begin(eventSpace), std::end(eventSpace), [=](int n) {return n == space;})) {
        eventRandomizor();
    }

}

void winConditions() {
    if (p_Pos[p_Cur] >= 91) {
        endTurn();
    }
}