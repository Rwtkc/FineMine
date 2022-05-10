#include"game.h"
int get_mine_number(char mine[ROWS][COLS], char show[ROWS][COLS],int row, int col,int x,int y)//��ȡ�׵ĸ�������
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
				count1++;//���׵ĸ���
			}
		}
	}
	return count - count1+48;//Ascii��ת��;
}
//void Extend(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)//��չ����
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
//�Ķ��벻������չ��ôдc}
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)//��ʼ������
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
void DisplayBoard(char board[ROWS][COLS], int row, int col)//��ӡ���̺���
{
	int i = 0;
	int j = 0;
	printf("  ");//�������ϽǵĿո������ã�
	for (i = 1; i <= row; i++)//��ӡ�����
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1;i <= row;i++)
	{
		printf("%d ", i);//��ӡ�����
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char board[ROWS][COLS], int row, int col)//�����׺���
{
	int mine1 = mines;//�����׵ĳ�ʼ����
	while (mine1)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';//'1'������
			mine1--;//�������ֹ�����ظ�
		}
	}
}
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//ɨ�׺���
{
	int x = 0;
	int y = 0;
	int win = 0;//���׵ĸ���
	while (1)
	{
		printf("������Ҫɨ������->:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (mine[x][y] == '1')
			{
				printf("���ź��㱻ը����\n");
				printf("����ͼ����:\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				show[x][y] = get_mine_number(mine,show,row,col,x,y);//��ȡ�׵ĸ���
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
			printf("����Ƿ������������룡");
		}
	}
	if (win == row*col-mines)
	{
		printf("��Ϸʤ����\n");
		printf("����ͼ����\n");
		DisplayBoard(mine, ROW, COL);
	}
}
