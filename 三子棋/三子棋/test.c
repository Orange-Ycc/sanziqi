#define  _CRT_SECURE_NO_WARNINGS 1

//����


#include"game.h"

void menu()
{
	printf("***********************************\n");
	printf("*****	1��play		0��exit   *****\n");
	printf("***********************************\n");
}

void game()
{
	char board[ROW][COL] = { 0 };
	//��ʼ������
	Initialboard(board, ROW, COL);
	//��ӡ����
	Displayboard(board, ROW, COL);

	//������Ϸ����״̬
	char ret = 0;
	// *  ���Ӯ
	// #  ����Ӯ
	// C  ��Ϸ����
	// Q  ƽ��

	while (1)
	{
		//�������
		Playergo(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		//��������
		Computergo(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ��\n");
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
		printf("��ѡ��>��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//printf("��ʼ��Ϸ��\n");
			game();
			break;
		case 0:
			printf("������Ϸ��\n");
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}