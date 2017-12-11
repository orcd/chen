#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
	 天生棋局。有两个函数原型的题目可任意实现一个
1.	 传入一个n 在堆空间中产生n*n方格的棋盘
int ** createBoard(int n);
int   createBoard1(int ***p,int n);
2.	 N颗棋子随机落在棋盘上<需要防止落在同一位置>
int  initBoard(int **p,int n);
3.	 打印棋盘
int  printBoard(int **p,int n);
如果有两颗棋子落同一行或者同一列 输出好棋
否则 输出 不是好棋
将棋局中的棋子打印出来 空位用O
有旗子的用X表示
4.	销毁棋盘
int  destroyBoard(int **p,int n);
int  destroyBoard1(int ***p,int n);

*/
//arr[2][3];


//1.	 传入一个n 在堆空间中产生n*n方格的棋盘
int ** createBoard(int n)
{
	int **p = (int **)malloc(sizeof(int *)*n);
	int i;
	for (i = 0; i<n; ++i)
	{
		p[i] = (int *)malloc(sizeof(int)*n);

		memset(p[i], 0, sizeof(int)*n);
	}
	return p;
}
int   createBoard1(int ***p, int n)
{
	int **tmp = (int **)malloc(sizeof(int *)*n);
	int i;
	for (i = 0; i<n; ++i)
	{
		tmp[i] = (int *)malloc(sizeof(int)*n);
		memset(p[i], 0, sizeof(int)*n);
	}
	*p = tmp;
	return 0;
}
//销毁棋盘
int  destroyBoard(int **p, int n)
{
	int i;
	for (i = 0; i<n; ++i)
	{
		free(p[i]);
	}
	free(p);
	return 0;
}
int  destroyBoard1(int ***p, int n)
{
	int **tmp = *p;
	int i;
	for (i = 0; i<n; ++i)
	{
		free(tmp[i]);
	}
	free(tmp);
	*p = NULL;

	return 0;
}

//2.	 N颗棋子随机落在棋盘上<需要防止落在同一位置>
int  initBoard(int **p, int n)
{
	//8 * 8
	int i;
	int randx = 0, randy = 0;
	for (i = 0; i<n; ++i)//循环落子  5
	{
		randx = rand() % n;
		randy = rand() % n;
		if (p[randy][randx] == 0)//如果落子的地方是0就说明没落过子可以落子
		{
			p[randy][randx] = 1;
		}
		else//否则的话就是落过子了从新来过
		{
			--i;
		}
	}
	return 0;
}

//3.	 打印棋盘
int  printBoard(int **p, int n)
{
	int i, j;						//用来做循环的参数
	int sumline = 0, sumrow = 0;	//列,行
	int flag = 0;					//做标识
	for (i = 0; i<n; ++i)
	{
		sumline = 0;//列
		sumrow = 0;//行
		//line
		for (j = 0; j<n; ++j)
		{
			if (p[i][j] == 0)
				printf(" O");
			else if (p[i][j] != 0)
				printf(" X");
			if (flag == 0)
			{
				sumline += p[i][j];
				sumrow += p[j][i];
			}
		}
		putchar('\n');
		if (sumline > 1 || sumrow >1)
		{
			flag = 1;
		}
	}
	if (flag == 1)
		printf("好\n");
	else
		printf("坏\n");
}
int main(void)
{
	int n;
	scanf("%d", &n);					//获取一个输入的数值
	int **p = createBoard(n);			//根据数入的数值来创建棋盘空间


	initBoard(p, n);					//落子

	printBoard(p, n);					//打印棋盘

	destroyBoard1(&p, n);				//销毁棋盘
	if (p != NULL)
		printBoard(p, n);

	system("pause");
	return EXIT_SUCCESS;
}
