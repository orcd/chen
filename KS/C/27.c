/*输入一个字符串，判断其是否是回文。(回即正读和反读都一样，如abcba，abba)*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define N 128

int  func(const char * str)
{
	int len = strlen(str);
	int i = 0;
	for (i = 0; i < len / 2; ++i) 
	{
		// 拿第一个字符和最后一个字符比较（注意省去'\0')
		if (*(str + i) != *(str + len - i - 1)) 
		{
			return 1;			// 只要有一个字符不想等，就直接返回0
		}
	}
	return 0;
}

int main(void)
{
	int ret = 0;
	char str[N] = { 0 };
	printf("请输入字符串:\n");
	//fgets(str, N, stdin);
	scanf("%s", str);
	ret = func(str);
	if (0 == ret )			// 如果返回1，表示是回文
		printf("Yes! %s is a huiwen!\n", str);
	else								// 否则不是回文
		printf("Noo! %s in not a huiwen!\n", str);
	return 0;
}