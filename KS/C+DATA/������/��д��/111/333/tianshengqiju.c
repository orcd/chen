/*
天生棋局。有两个函数原型的题目可任意实现一个
1)  传入一个n 在堆空间中产生n*n方格的棋盘
int ** createBoard(int n);
int   createBoard1(int***p,int n);
2)  N颗棋子随机落在棋盘上<需要防止落在同一位置>
int  initBoard(int**p,int n);
3)  打印棋盘
int  printBoard(int**p,int n);
如果有两颗棋子落同一行或者同一列 输出好棋
否则 输出 不是好棋
将棋局中的棋子打印出来 空位用O
有旗子的用X表示
4)  销毁棋盘
int  destroyBoard(int**p,int n);
int  destroyBoard1(int***p,int n);
*/

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int ** createBoard(int n)
{
	if (n <= 0)
	{
		return NULL;
	}

	int **a = (int **)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++)
	{
		a[i] = (int *)malloc(sizeof(int)*n);
		for (int j = 0; j < n; j++)
		{
			a[i][j] = 0;
		}
	}
	return a;
}
int  initBoard(int**p, int n)
{
	if (p == NULL)
	{
		return;
	}
	
	
	int x, y;
	for (int i = 0; i < n; i++)
	{
		int pos = rand() % (n*n);
		x = pos / n ;
		y = pos % n ;
		p[x][y] = 1;
	}
	int * h = malloc(sizeof(int));
	int * l = malloc(sizeof(int));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			h[i] += p[i][j];
			l[i] += p[j][i];
		}
		if (h[i] == 2 || l[i] == 2)
		{
			printf("good \n");
			return;
		}
	}
	printf("bad");
	return;
}
int  printBoard(int**p, int n)
{
	if (p == NULL)
	{
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
	printf("=========================================\n");
}
int  destroyBoard(int**p, int n)
{
	if (p == NULL)
	{
		return;
	}
	for (int i = 0; i < n; i++)
	{
		free(p[i]);
		p[i] = NULL;
	}
	free(p);
	p = NULL;
}
void test()
{
	int n = 10;
	int ** a = createBoard(n);
	printBoard(a, n);
	initBoard(a,n);
	printBoard(a, n);
	destroyBoard(a, n);
}

int main()
{
	srand((unsigned int)time(NULL));
	test();

	system("pause");
	return 0;
}