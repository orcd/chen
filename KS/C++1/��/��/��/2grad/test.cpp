
#define  _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "mystring.h"
#include "graduate.h"
using namespace std;

void test()
{
	graduate a("xiaoming", 1, 100, "xiaoming");
	graduate b("xiaowang", 2, 50, "xiaowang");
	graduate c("xiaoxing", 3, 80, "xiaoxing");
	a.display();
	b.display();
	c.display();
	cout << stu::avrscore() << endl;
}

int main(int argc, char * argv[])
{
	test();

	system("pause");
	return 0;
}