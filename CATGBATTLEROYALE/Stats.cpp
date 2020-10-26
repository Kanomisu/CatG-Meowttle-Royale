#include "resources.h"

int p_Max = 2; //Max amount of players - 1
//int p_Max_Health[3] = {100,100,100};

int p_Cur = 0; //Current player (p1 = 0, p2 = 1, p3 = 2)

int p_Pos[3] = { 0,0,0 };   //player current postion on the board
int p_S_A[3] = { 0,0,0 }; //player attack stat
int p_S_V[3] = { 0,0,0 }; //player vitality stat
int p_S_R[3] = { 0,0,0 }; //player resistance stat
int p_S_L[3] = { 0,0,0 }; //player luck stat

bool p_SellSoul[3] = { false ,false ,false }; //0 = they didn't sell their soul 1 = they did sell their soul

int p_Health[3] = { 1,1,1 }; //player health

bool p_Skipped[3] = { false, false, false }; //Skip next turn of current player

bool p_Finished[3] = { false, false, false }; //Inicator when the player has finished the board.

bool p_FinishedFirst[3] = { false, false, false };//Indicates if the player was the first one to finish

bool p_Winner[3] = { false, false, false }; //indicates who is the final winner

int skipCount[3] = { 0, 0 , 0 }; //Count to make sure the player turn is skipped

/*
bool p_1_S = false; //Skip next turn of P1
bool p_2_S = false; //Skip next turn of P2
bool p_3_S = false; //Skip next turn of P3
*/