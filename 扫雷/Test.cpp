#include<stdio.h>
#pragma warning(disable:4996)
#include"game.h"
void menu()//�˵�����
{
	printf("******������*********\n");
	printf("******1.play*********\n");
	printf("******2.exit*********\n");
}
void game()
{
	char set = '0';
	char set1 = '*';
	char mine[ROWS][COLS] = { 0 };//��̨��������
	char show[ROWS][COLS] = { 0 };//չʾ����
	InitBoard(mine,ROWS,COLS,'0');//��ʼ����̨���̺���,��ʼֵΪ'0'
	InitBoard(show,ROWS,COLS,'*');//��ʼ��ǰ̨���̺���,��ʼֵΪ'*'
	//DisplayBoard(mine,ROW,COL);//��ӡ��̨���̺���
	//printf("\n");
	DisplayBoard(show,ROW,COL);//��ӡǰ̨���̺���
	SetMine(mine, ROW, COL);//�����׺���
	printf("\n");
	//DisplayBoard(mine, ROW, COL);//��ӡ��̨���̺����������׺�
	FineMine(mine,show,ROW,COL);//ɨ�׺���
}
int main()
{
	srand((unsigned int)time(NULL));//�������ֵ�������겼����
	int n = 0;
	menu();
	printf("��ѡ��->:");
	scanf("%d", &n);
	switch (n)
	{
	case 1://��ʼ��Ϸ
		game();
		break;
	case 2://��Ϸ�˳�
		printf("��Ϸ�˳���");
		break; default:
			getchar();//�������ּ��
			printf("������ѡ��\n");
			break;
	}
	return 0;
}
