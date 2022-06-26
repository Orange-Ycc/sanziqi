#include "game.h"
#define  _CRT_SECURE_NO_WARNINGS 1


//��������


//��ʼ������
void Initialboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			//����������Ԫ�ض���ʼ��Ϊ�ո�
			board[i][j] = ' ';
		}
	}
}

//��ӡ���Ź���
// 
//_ _|_ _|_ _
//_ _|_ _|_ _
//   |   |
void Displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			//1.��ӡһ�е�����   ��   |   |   ��
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//2.��ӡ�ָ��� ��---|---|---��
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void Playergo(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("����ߣ�>\n");
	while (1)
	{
		printf("������Ҫ���ӵ����꣺>");
		scanf("%d%d", &x, &y);
		//�ж�����ĺϷ��ԣ��Ƿ�����������
		if (1 <= x && x <= row && y >= 1 && y <= col)
		{
			//�ж�����������Ƿ�ռ��
			if (board[x - 1][y - 1] == ' ')
			{
				//���û��ռ�ã��͸������������긳ֵΪ*
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("��������ռ�ã�\n");
			}
		}
		else
		{
			printf("�������겻�Ϸ������������룡\n");
		}
	}
}


void Computergo(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����ߣ�>\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//�ж������Ƿ����
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//�ж�����
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}

	//�ж϶Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//�ж�ƽ��
	//����������ˣ�����1��ƽ��
	//û������0
	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}
	return 'C';
}
