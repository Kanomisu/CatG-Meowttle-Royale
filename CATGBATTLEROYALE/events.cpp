#include "resources.h"
#include <algorithm>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

/*
int restSpace[1] = { 2 };
int fatigueSpace[1] = { 12 };
int gambleSpace[1] = { 4 };
int battleSpace[1] = { 9 };
*/

int backSpace[8] = { 6, 18, 30, 42, 56, 68, 80, 90 };
int forwardSpace[8] = { 2, 12, 24, 36, 48, 60, 72, 84 };
int eventSpace[22] = { 3, 7, 11, 15, 19, 23, 27, 31, 35, 39, 43, 47, 51, 55, 59, 63, 67, 71, 75, 79, 83, 87 };

int pickedNum[3] = { 0,0,0 }; //sell soul number picked

bool ranSellSoul = false;

int response = 0;
int gamNum = 0;

int rNum = 0;

void back();
void forward();
void rest();
void fatigue();
void battle();
void gamble();
void soulDia();
//back     1
//forward  2
//rest     3
//fatigue  4
//gamble   5
//battle   6


int random() {
    return rand() % 5 + 1;
}


void eventRandomizer() {
    std::cout << "You have landed upon an event space, a random event shall now occur...\n";
    rNum = rand() % 6;
    switch(rNum) {
    case(0):
        back();
        break;
    case(1):
        forward();
        break;
    case(2):
        rest();
        break;
    case(3):
        fatigue();
        break;
    case(4):
        battle();
        break;
    case(5):
        gamble();
        break;
    }
}

void back() {
    std::cout << "As you travelled, you tornado hit you! You were flung back 3 spaces!\n";
    if (p_Pos[p_Cur] >= 3) {
        p_Pos[p_Cur] -= 3;
    }
    else {
        p_Pos[p_Cur] = 0;
    }
    std::cout << "You are now at space " << p_Pos[p_Cur] << "\n";
}

void forward() {
    std::cout << "Upon your journey, you found a shortcut, you moved 3 spaces forward!\n";
    p_Pos[p_Cur] += 3;
    std::cout << "You are now at space " << p_Pos[p_Cur] << "\n";
}

void rest() {
    //p_Skipped[p_Cur] = true;
    std::cout << "You stumbble upon an inn to stay at. Your health has been fully replenished!\n";
    p_Health[p_Cur] = p_S_V[p_Cur];
}

void fatigue() {
    std::cout << "You find yourself weary, and take a short break. Your next turn has been skipped!\n";
    p_Skipped[p_Cur] = true;
}

void gamble() {
    system("CLS");
    currentBoard();
    std::cout << "You have have been chosen for a small gamble, you will either gain or lose a stat depending on your answer...\n";
    std::cout << "Pick a stat you would like to improve. \n 1. Attack \n2. Vitality \n3. Resistance \n4. Luck\n";
    std::cin >> response;
    std::cout << "\nPick 1 or 2\n";
    std::cin >> gamNum;
    rNum = rand() % 2 + 1;
    if (rNum == gamNum) {
        std::cout << "Congratulations you have chosen correctly!\n";
        switch (response) {
        case(1):
            p_S_A[p_Cur] += 1;
            std::cout << "Attack +1! Your attack stat is now " << p_S_A[p_Cur] <<  "\n";
            break;
        case(2):
            p_S_V[p_Cur] += 1;
            std::cout << "Vitality +1! Your vitality stat is now " << p_S_V[p_Cur] << "\n";
            break;
        case(3):
            p_S_R[p_Cur] += 1;
            std::cout << "Resistance +1! Your resistance stat is now " << p_S_R[p_Cur] << "\n";
            break;
        case(4):
            p_S_L[p_Cur] += 1;
            std::cout << "Luck +1! Your luck stat is now " << p_S_L[p_Cur] << "\n";
            break;
        }
    }
    else {
        std::cout << "Wrong number kiddo, you should've chosen " << rNum << "!\n";
        switch (response) {
        case(1):
            p_S_A[p_Cur] -= 1;
            std::cout << "Attack -1! Your attack stat is now " << p_S_A[p_Cur] << "\n";
            break;
        case(2):
            p_S_V[p_Cur] -= 1;
            std::cout << "Vitality -1! Your vitality stat is now " << p_S_V[p_Cur] << "\n";
            if (p_Health[p_Cur] > p_S_V[p_Cur])
            {
                p_Health[p_Cur] = p_S_V[p_Cur];
            }
            break;
        case(3):
            p_S_R[p_Cur] -= 1;
            std::cout << "Resistance -1! Your resistance stat is now " << p_S_R[p_Cur] << "\n";
            break;
        case(4):
            p_S_L[p_Cur] -= 1;
            std::cout << "Luck -1! Your luck stat is now " << p_S_L[p_Cur] << "\n";
            break;
        }
    }
}

//Fight Option
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
                std::cout << "Player 1 has successfully guessed the correct number!\n[DEVIL] Good work, loyal servant of mine! The price shouldn't be too high for you...";
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
                std::cout << "Player 1 has failed to guess the correct number!\n[DEVIL] That's a real shame aint it? Oh well, your punishment is now active";
            }
        }
        else if (p_Cur == 1) {
            if (pickedNum[1] == pickedNum[0] || pickedNum[1] == pickedNum[2]) {
                std::cout << "Player 2 has successfully guessed the correct number!\n[DEVIL] Good work, loyal servant of mine! The price shouldn't be too high for you...";
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
                std::cout << "Player 2 has failed to guess the correct number!\n[DEVIL] That's a real shame aint it? Oh well, your punishment is now active";
            }
        }
        else if (p_Cur == 2) {
            if (pickedNum[2] == pickedNum[0] || pickedNum[2] == pickedNum[1]) {
                std::cout << "Player 3 has successfully guessed the correct number!\n[DEVIL] Good work, loyal servant of mine! The price shouldn't be too high for you...";
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
                std::cout << "Player 3 has failed to guess the correct number!\n[DEVIL] That's a real shame aint it? Oh well, your punishment is now active";
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

int player(int cPlayer) {
    int totalStats;
    totalStats = p_Health[cPlayer] + p_S_V[cPlayer] + p_S_A[cPlayer] + p_S_R[cPlayer] + p_S_L[cPlayer];
    std::cout << "Player " << cPlayer + 1 << "\n" <<
        "HP: " << p_Health[cPlayer] << "/" << p_S_V[cPlayer] << "\n" <<
        "Attack: " << p_S_A[cPlayer] << "\n" << "Resistance: " << p_S_R[cPlayer] << "\n" <<
        "Luck: " << p_S_L[cPlayer] << "\n" << "Stat Total = " << totalStats << "\n";
    if (p_FinishedFirst[cPlayer])
    {
        std::cout << "This player managed to finish first, +2 to his final score!!!!\n";
        totalStats += 2;
        std::cout << "There final score is now " << totalStats;
    }
    return totalStats;

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
        eventRandomizer();
    }

}

void winConditions() {
    if (p_Pos[p_Cur] >= 91) {
        endTurn();
    }
}

/*Gives player their stats after battle
Enemy's ID's are as follows:
1. Shield Slime
2. Slime O'Luck
3. Slime of Gains
4. Power Slime
*/

void statGiver(int enemyFaced) {
    int resistanceGiven = 1;
    int luckGiven = 2;
    int vitalityGiven = 3;
    int strengthGiven = 4;
    int statGiven = 0;

    switch (enemyFaced)
    {
    case 1:
        p_S_R[p_Cur] += 1;
        break;
    case 2:
        p_S_L[p_Cur] += 1;
        break;
    case 3:
        p_S_V[p_Cur] += 1;
        break;
    case 4:
        p_S_A[p_Cur] += 1;
        break;
    }
}