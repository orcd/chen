//输入3名学生和各学生的4门课的成绩，计算每个学生的总分成绩和平均成绩，结果保留一位小数

#include <stdio.h>

int main(void)
{
	float stu[3][4] = { 0 };
	float sum = 0;

	for(int i = 0; i < 3; ++i)		
	{
		printf("请输入第%d个学生的成绩:\n",i+1);   
		for(int j = 0; j < 4; ++j)
			scanf("%f", &stu[i][j]);
	}

	for(int i = 0; i < 3; ++i)
	{
		sum = 0;
		for(int j = 0; j < 4; ++j)
			sum += stu[i][j];
		printf(" 第%个学生的总分为%d,平均分为%.1f \n", i+1, sum, sum / 4.0);
	}

	return 0;

