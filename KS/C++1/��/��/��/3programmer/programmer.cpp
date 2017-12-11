/*
3、编写一个C++程序, 计算程序员( programmer )工资，programmer设置为抽象接口类。								20'
class programmer
{
public:
virtual int getSal() = 0;
};

1）程序员属性拥有：工资，年龄，名字(int sal; int age; char name[128];)
2）要求能计算出初级程序员 ( junior_programmer ) 中级程序员 ( mid_programmer ) 高级程序员 ( adv_programmer ) 的工资
2）要求利用抽象类统一界面，方便程序的扩展，比如：新增计算 架构师 ( architect ) 的工资
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma  once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

class programmer
{
public:
	virtual int getSal() = 0;
	programmer(int sal1,int age1,char* name1) 
	{
		this->age = age1;
		strcpy(this->name, name1);
		this->sal = sal1;
	}

protected:
	int sal; 
	int age; 
	char name[128];
};

class junior_programmer : public programmer
{
public:
	junior_programmer(int s, int a, char *n) :programmer(s,a,n)
	{
	}

	virtual int getSal()
	{
		return sal;
	}
};

class mid_programmer : public programmer
{
public:
	mid_programmer(int s, int a, char *n, int j) :programmer(s, a, n), jiaban(j)
	{
	}
	virtual int getSal()
	{
		return sal+jiaban;
	}

private:
	int jiaban;//加班费

};

class adv_programmer : public programmer
{
public:
	adv_programmer(int s, int a, char *n, int b, int o) :programmer(s, a, n), bonus(b), other(o)
	{
	}

	virtual int getSal()
	{
		return sal+bonus+other;
	}

private:
	int bonus;
	int other;
};

//architect
class architect : public programmer
{
public:
	architect(int s, int a, char *n) :programmer(s, a, n)
	{
	}
	virtual int getSal()
	{
		return sal;
	}
};

//类型兼容，父类指针，父类引用 指针 子类对象
//框架
void fun(programmer *p)
{
	cout << "sal = " << p->getSal() << endl;
}

int main()
{
	junior_programmer junior(5000, 24, "lily");
	mid_programmer mid(12000, 28, "lelei",1000);
	adv_programmer adv(20000, 32, "shiye",10000,500);

	fun(&junior);
	fun(&mid);
	fun(&adv);


	architect obj(40000, 35, "shiye");
	fun(&obj);

	cout << "\n";
	system("pause");
	return 0;
}