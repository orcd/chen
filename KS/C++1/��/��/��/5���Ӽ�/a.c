/*4、算法实现  {0，1，2，3，4，5，6，7，8，9，10，11，.......  20}  请打印所以的子集 ，并写入文件 			 10'*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test()
{
	//int num[21] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20 };
	int num[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	FILE * fp = fopen("d:/a.txt", "w+");
	unsigned long long x = 1; //0-2^64
	int max = 10;
	for (int i = 0; i < max; i++)
	{
		x *= 2;  //1024
	}
	char arr[4];
	for (unsigned long long j = 0; j < x; j++)
	{
		int pos = 0;
		unsigned long long k = j;
		while (k != 0)
		{
			if (k%2 ==1)
			{
				memset(arr, 0, 4);
				sprintf(arr, "%d\t", num[pos]);
				//printf("%d\t", num[pos]);
				fwrite(arr, 1, 4, fp);
			}
			pos++;
			k /= 2;

		}
		fwrite("\n", 1, 1, fp);
		printf("\n");
		//getchar();
	}

	fclose(fp);
	
}

int main()
{
	test();

	system("pause");
	return 0;
}