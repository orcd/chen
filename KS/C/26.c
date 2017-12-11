/*
	用C语言循环语句打印一个如下图的三角形

	      *
	     **
	    ***
	   ****
      *****

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(int num)
{
	int i = 0, j = 0, k = 0;
	// 
	for (i = 0; i < num; ++i) 
	{
		//
		for (j = 0; j < num - i; ++j) 
		{
			putchar(' ');
		}
		for (k = 0; k < i+1; ++k) 
		{
			//输出 *
			putchar('*');
		}
		printf("\n");
	}
}

int main(void)
{
	int n = 0;
	/*printf("请输入你要的层数:");
	scanf("%d", &n);
	func(n)*/
	func(5);
	return 0;
}

