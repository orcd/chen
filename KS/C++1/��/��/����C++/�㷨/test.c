#include <stdio.h>  

//k�ǿ�ʼ�ַ���λ�ã�n������ĳ���,l���Ӽ���λ��  
void subArray(int A[], int k, int l, int n);
//��ʼ�������Ӽ�����  
void initArray(int n);
//��������Ӽ�������  
int priArray[20];
void printArray(int n);
int counter = 0;

int main()
{
	int i;
	int array[4] = { 0, 2, 3, 4 };
	int n = 4;
	//0������������Ӽ� 
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
		//�ݹ��㷨��Ҫ��֤�ӵ�һ��Ԫ�ؿ�ʼ�����е�Ԫ�ض���������  
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
* �õݹ��㷨ÿ��ֻ���Ѱ��һλ���֡�
* ����k=1ʱ��ֻ��Ѱ��2��3��4;k=2ʱ��ֻ��Ѱ��3��4
*/

void subArray(int A[], int k, int l, int n)
{
	int i;

	if (k == n - 1)
	{
		//n����������ĳ��ȣ�k�������Ӽ�����һλ�ַ�����k == n-1ʱ����ζ���Ѿ������һ���ˡ�  
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
* ��ӡ�Ӽ�����ĺ���
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