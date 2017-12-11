/*
2、从1中的学生类派生出一个研究生类(Graduate)，研究生比学生多出一个导师信息（导师名），	（分文件编程）		15'
并设计接口函数，用来显示研究生信息，包括 学号、姓名、成绩、导师信息。

并编写main函数进行测试：
输出如：
学号 	姓名   	成绩		导师
1	  	张XX		98		王XX
2		王XX		90		XXX
3		XXX		89		XXX
平均成绩：	XX
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma  once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "mystring.h"
#include "stu.h"
using namespace std;

class graduate: virtual public stu
{
public:
	graduate(MyString  name, int id, double score, MyString teacher);
	void display();
	MyString getteacher();

protected: 
	MyString teacher;
};