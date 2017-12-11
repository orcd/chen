/*1、设计一个学生类，包括学号、姓名、成绩，并设计接口函数用来输出这些学生数据并计算平均分。（分文件编程）		25'
a) 姓名不能是 char *, 要求是MyString的对象成员
b) 不能使用全局变量，用static成员代替
c) 成员变量应该是私有，通过公有接口访问
d) 编写main函数进行测试：
输出如：
学号 	姓名    成绩
1		张XX		98
2		王XX		90
3		XXX		89
平均成绩：	XX
*/

#define  _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "mystring.h"
using namespace std;

class stu
{
public:
	stu(MyString  name, int id, double score);
	
	MyString getname();
	int getid();
	double getscore();

	static double avrscore();
private:
	MyString name;
	int id;
	double score;


	//静态成员
	static int num;//人数
	static double totalscore;
};