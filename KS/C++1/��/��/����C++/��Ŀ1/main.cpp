#include <iostream>
#include "test01.h"
using namespace std;
int main()
{
	Student s1(1, "张三", 98);
	Student s2(2, "李四", 90);
	Student s3(3, "王二", 89);
	int score = (s1.getscore() + s2.getscore() + s3.getscore()) / 3;
	printf("学号    姓名    成绩\n");
	s1.printStu();
	s2.printStu();
	s3.printStu();
	printf("平均成绩：%d\n", score);
	system("pause");
	return 0;
}