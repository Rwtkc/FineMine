#include"game.h"
int get_mine_number(char mine[ROWS][COLS], char show[ROWS][COLS],int row, int col,int x,int y)//获取雷的个数函数
{
	int i = 0;
	int j = 0;
	int count = 0;
	int count1 = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			count++;//9
			if (mine[i][j] == '0')
			{
				count1++;//非雷的个数
			}
		}
	}
	return count - count1+48;//Ascii码转换;
}
//void Extend(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)//扩展函数
//{
//	int i = 0;
//	int j = 0;
//	for (i = x - 1; i <= x + 1&&i>=1&&i<=row; i++)
//	{
//		for (j = y - 1; j <= y + 1&&j>=1&&j<=col; j++)
//		{
//			if (mine[i][j] == '1')
//			{
//				show[x][y] = get_mine_number(mine, show, ROW, COL, x, y);
//				return;
//			}
//			if (mine[i][j] == '0')
//			{
//				show[i][j] = '0';
//				x = i;
//				y = j;
//				Extend(mine, show, ROW, COL, x, y);
//			}
//		}
//	}
//四都想不出来扩展怎么写c}
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)//初始化函数
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)//打印棋盘函数
{
	int i = 0;
	int j = 0;
	printf("  ");//棋盘左上角的空格（美观用）
	for (i = 1; i <= row; i++)//打印行序号
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1;i <= row;i++)
	{
		printf("%d ", i);//打印列序号
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char board[ROWS][COLS], int row, int col)//布置雷函数
{
	int mine1 = mines;//设置雷的初始个数
	while (mine1)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';//'1'代表雷
			mine1--;//放这里防止布置重复
		}
	}
}
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//扫雷函数
{
	int x = 0;
	int y = 0;
	int win = 0;//非雷的个数
	while (1)
	{
		printf("请输入要扫的坐标->:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾你被炸死了\n");
				printf("棋盘图如下:\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				show[x][y] = get_mine_number(mine,show,row,col,x,y);//获取雷的个数
				DisplayBoard(show, ROW, COL);
				win++;
				if (win == row*col-mines)
				{
					break;
				}
			}
		}
		else
		{
			getchar();
			printf("坐标非法！请重新输入！");
		}
	}
	if (win == row*col-mines)
	{
		printf("游戏胜利！\n");
		printf("棋盘图如下\n");
		DisplayBoard(mine, ROW, COL);
	}
}
