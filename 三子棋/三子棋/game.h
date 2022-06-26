#define  _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define COL 3

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Initialboard(char board,int row,int col);
void Displayboard(char board,int row, int col);
void Playergo(char board, int row, int col);
void Computergo(char board, int row, int col);


char IsWin(char board, int row, int col);
//º¯ÊýÉùÃ÷