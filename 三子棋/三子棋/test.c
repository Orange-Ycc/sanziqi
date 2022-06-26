#define  _CRT_SECURE_NO_WARNINGS 1

//测试


#include"game.h"

void menu()
{
	printf("***********************************\n");
	printf("*****	1、play		0、exit   *****\n");
	printf("***********************************\n");
}

void game()
{
	char board[ROW][COL] = { 0 };
	//初始化数组
	Initialboard(board, ROW, COL);
	//打印棋盘
	Displayboard(board, ROW, COL);

	//接收游戏返回状态
	char ret = 0;
	// *  玩家赢
	// #  电脑赢
	// C  游戏继续
	// Q  平局

	while (1)
	{
		//玩家下棋
		Playergo(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		//电脑下棋
		Computergo(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("玩家赢了\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局\n");
	}
	//DisplayBoard(board, ROW, COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择>：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//printf("开始游戏！\n");
			game();
			break;
		case 0:
			printf("结束游戏！\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}