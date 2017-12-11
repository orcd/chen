#include <stdio.h>  

//k是开始字符的位置，n是数组的长度,l是子集的位数  
void subArray(int A[], int k, int l, int n);
//初始化整个子集数组  
void initArray(int n);
//用于输出子集的数组  
int priArray[20];
void printArray(int n);
int counter = 0;

int main()
{
	int i;
	int array[4] = { 0, 2, 3, 4 };
	int n = 4;
	//0是所有数组的子集 
	for(i = 0; i < n; ++i)
	{
		if (array[i] == 0)
		{
			break;
		}
	}
	if (i == n)
	{
		printf("0\n");
		counter += 1;
	}
	for (i = 0; i < n; i++)
	{
		initArray(n);
		//递归算法需要保证从第一个元素开始的所有的元素都被遍历到  
		priArray[0] = array[i];
		counter += 1;
		printArray(1);
		subArray(array, i + 1, 2, 4);
	}
	printf("\nThe SubArray is %d\n", counter);
	system("pause");
	return 0;
}

/*
* 该递归算法每次只向后寻找一位数字。
* 例如k=1时，只会寻找2，3，4;k=2时，只会寻找3，4
*/

void subArray(int A[], int k, int l, int n)
{
	int i;

	if (k == n - 1)
	{
		//n是整个数组的长度，k是整个子集的上一位字符，当k == n-1时，意味着已经是最后一个了。  
		priArray[l - 1] = A[k];
		counter += 1;
		printArray(l);
	}
	else
	{
		for (i = k; i <= n - 1; ++i)
		{
			priArray[l - 1] = A[i];
			counter += 1;
			printArray(l);
			subArray(A, i + 1, l + 1, n);
		}
	}

}

/*
* 打印子集数组的函数
*/

void printArray(int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d  ", priArray[i]);
	}
	printf("\n");
}

void initArray(int n)
{
	for (int i = 0; i <= n - 1; i++) {
		priArray[i] = 0;
	}
}