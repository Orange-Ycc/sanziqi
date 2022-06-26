#include "game.h"
#define  _CRT_SECURE_NO_WARNINGS 1


//函数定义


//初始化数组
void Initialboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			//把数组所有元素都初始化为空格
			board[i][j] = ' ';
		}
	}
}

//打印出九宫格
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
			//1.打印一行的数据   “   |   |   ”
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//2.打印分隔行 “---|---|---”
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
	printf("玩家走：>\n");
	while (1)
	{
		printf("请输入要下子的坐标：>");
		scanf("%d%d", &x, &y);
		//判断输入的合法性，是否在坐标轴内
		if (1 <= x && x <= row && y >= 1 && y <= col)
		{
			//判断输入的坐标是否被占用
			if (board[x - 1][y - 1] == ' ')
			{
				//如果没有占用，就给玩家输入的坐标赋值为*
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标已占用！\n");
			}
		}
		else
		{
			printf("输入坐标不合法，请重新输入！\n");
		}
	}
}


void Computergo(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走：>\n");
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
	//判断三行是否相等
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//判断三列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}

	//判断对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//判断平局
	//如果棋盘满了，返回1，平局
	//没满返回0
	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}
	return 'C';
}
