#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)
#define mines 10//�׵ĸ���
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set);
void DisplayBoard(char board[ROWS][COLS],int row,int col);
void SetMine(char board[ROWS][COLS], int row, int col);
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);