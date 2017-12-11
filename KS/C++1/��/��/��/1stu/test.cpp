
#define  _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "mystring.h"
#include "stu.h"
using namespace std;

void test()
{
	stu a("xiaoming", 1, 100);
	stu b("xiaowang", 2, 50);
	stu c("xiaoxing", 3, 80);

	cout << stu::avrscore() << endl;
}

int main(int argc, char * argv[])
{
	test();

	system("pause");
	return 0;
}