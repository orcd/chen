/*
������֡�����������ԭ�͵���Ŀ������ʵ��һ��
1)  ����һ��n �ڶѿռ��в���n*n���������
int ** createBoard(int n);
int   createBoard1(int***p,int n);
2)  N�������������������<��Ҫ��ֹ����ͬһλ��>
int  initBoard(int**p,int n);
3)  ��ӡ����
int  printBoard(int**p,int n);
���������������ͬһ�л���ͬһ�� �������
���� ��� ���Ǻ���
������е����Ӵ�ӡ���� ��λ��O
�����ӵ���X��ʾ
4)  ��������
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