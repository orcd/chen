//编写自定义冒泡排序函数 void BubbleSort(int *arr,int len)，使用指针传递的方式对十个数进行排序



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define N 10

// int *a, *b;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(int *arr, int len)
{
	for(int i = 0; i < len; ++i)
	{
		for(int j = 1; j < len - i; ++j)
		{
			if(*(arr + j) > *(arr + j - 1))
			{
				// int temp = *(arr + j);
				// *(arr + j) = *(arr + j - 1);
				// *(arr + j - 1) = temp;
				swap(arr + j, arr + j - 1);
			}
		}
	}
}


int main(void)
{
	int num[N] = { 0 };

	srand((unsigned int)time(NULL));
	
	for(int i = 0; i < N; ++i)
	{
		num[i] = rand() % 150 - 50;
	}

	BubbleSort(num, sizeof(num) / sizeof(int));

	for (int i = 0; i < N; ++i)
		printf("%d ", num[i]);
	printf("\n");
	return 0;
}
