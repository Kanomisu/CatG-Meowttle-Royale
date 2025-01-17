#pragma once

//Info about each int is in Stats.cpp

extern int p_Max;
//extern int p_Max_Health[];

extern int p_Cur;

extern int p_Pos[];
extern int p_S_A[];
extern int p_S_V[];
extern int p_S_R[];
extern int p_S_L[];

extern int p_Health[];

extern int skipCount[];

/*
extern bool p_1_S;
extern bool p_2_S;
extern bool p_3_S;
*/
extern bool p_Skipped[];
extern bool p_Finished[];
extern bool p_FinishedFirst[];
extern bool p_SellSoul[];

extern int rNum; //Random Number

void titleScreen();
void menu();
void endTurn();
int rollAnimation();
void cords(int x, int y);
void playerSelect();
void currentBoard();
void sellSoul();
void checkSpace(int cSpace);
int player(int cPlayer);
extern int backSpace[];