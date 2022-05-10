#include<stdio.h>
#pragma warning(disable:4996)
#include"game.h"
void menu()//菜单函数
{
	printf("******井子棋*********\n");
	printf("******1.play*********\n");
	printf("******2.exit*********\n");
}
void game()
{
	char set = '0';
	char set1 = '*';
	char mine[ROWS][COLS] = { 0 };//后台存雷棋盘
	char show[ROWS][COLS] = { 0 };//展示棋盘
	InitBoard(mine,ROWS,COLS,'0');//初始化后台棋盘函数,初始值为'0'
	InitBoard(show,ROWS,COLS,'*');//初始化前台棋盘函数,初始值为'*'
	//DisplayBoard(mine,ROW,COL);//打印后台棋盘函数
	//printf("\n");
	DisplayBoard(show,ROW,COL);//打印前台棋盘函数
	SetMine(mine, ROW, COL);//设置雷函数
	printf("\n");
	//DisplayBoard(mine, ROW, COL);//打印后台棋盘函数（布置雷后）
	FineMine(mine,show,ROW,COL);//扫雷函数
}
int main()
{
	srand((unsigned int)time(NULL));//利用随机值生成坐标布置雷
	int n = 0;
	menu();
	printf("请选择->:");
	scanf("%d", &n);
	switch (n)
	{
	case 1://开始游戏
		game();
		break;
	case 2://游戏退出
		printf("游戏退出！");
		break; default:
			getchar();//限制数字检测
			printf("请重新选择！\n");
			break;
	}
	return 0;
}
