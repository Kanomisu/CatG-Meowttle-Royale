#include "resources.h"

int p_Max = 2; //Max amount of players - 1
int p_Max_Health[3] = {100,100,100};

int p_Cur = 0; //Current player (p1 = 0, p2 = 1, p3 = 3)

int p_Pos[3] = { 0,0,0 };   //player current postion on the board
int p_S_A[3] = { 0,0,0 }; //player attack stat
int p_S_V[3] = { 0,0,0 }; //player vitality stat
int p_S_R[3] = { 0,0,0 }; //player resistance stat
int p_S_L[3] = { 0,0,0 }; //player luck stat

int p_Health[3] = { 100,100,100 }; //player health

bool p_1_S = false; //Skip next turn of P1
bool p_2_S = false; //Skip next turn of P2
bool p_3_S = false; //Skip next turn of P3