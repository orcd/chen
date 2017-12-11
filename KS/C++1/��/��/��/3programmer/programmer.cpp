/*
3����дһ��C++����, �������Ա( programmer )���ʣ�programmer����Ϊ����ӿ��ࡣ								20'
class programmer
{
public:
virtual int getSal() = 0;
};

1������Ա����ӵ�У����ʣ����䣬����(int sal; int age; char name[128];)
2��Ҫ���ܼ������������Ա ( junior_programmer ) �м�����Ա ( mid_programmer ) �߼�����Ա ( adv_programmer ) �Ĺ���
2��Ҫ�����ó�����ͳһ���棬����������չ�����磺�������� �ܹ�ʦ ( architect ) �Ĺ���
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
	int jiaban;//�Ӱ��

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

//���ͼ��ݣ�����ָ�룬�������� ָ�� �������
//���
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