#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class programmer
{
public:
	programmer()
	{
		this->sal = 0;
		this->age = 0;
		memset(this->name, 0, 128);
	}
	programmer(int sal, int age, char name[128])
	{
		this->sal = sal;
		this->age = age;
		memset(this->name, 0, 128);
		strcpy(this->name, name);
	}
	programmer(programmer& p)
	{
		sal = p.sal;
		age = p.age;
		memset(this->name, 0, 128);
		strcpy(name, p.name);
	}
	void setSal(int sal)
	{
		this->sal = sal;
	}
	void setAge(int age)
	{
		this->age = age;
	}
	void setName(char name[128])
	{
		memset(this->name, 0, 128);
		strcpy(this->name, name);
	}
	void Set(int sal, int age, char name[128])
	{
		this->sal = sal;
		this->age = age;
		memset(this->name, 0, 128);
		strcpy(this->name, name);
	}
	int getAge()
	{
		return this->age;
	}
	char* getName()
	{
		return this->name;
	}
	virtual int getSal() = 0;
	void print()
	{
		cout << "name=" << getName() << "  sal=" << getSal() << "  age=" << getAge() << endl;
	}
public:
	int sal;
	int age;
	char name[128];
};
/*
1）程序员属性拥有：工资，年龄，名字(int sal; int age; char name[128];)
2）要求能计算出初级程序员(junior_programmer) 中级程序员(mid_programmer) 高级程序员(adv_programmer) 的工资
2）要求利用抽象类统一界面，方便程序的扩展，比如：新增计算 架构师(architect) 的工资
*/
class junior_programmer :public programmer
{
public:
	virtual int getSal()
	{
		return sal*2;
	}
};
class mid_programmer :public programmer
{
public:
	virtual int getSal()
	{
		return sal * 3;
	}
};
class adv_programmer :public programmer
{
public:
	virtual int getSal()
	{
		return sal * 4;
	}
};
class architect :public programmer
{
public:
	virtual int getSal()
	{
		return sal * 5;
	}
};
void test01()
{
	programmer *p = new junior_programmer;
	p->Set(1200, 18, "zhangwei");
	p->print();

	programmer *p1 = new mid_programmer;
	p1->Set(1200, 18, "zhangwei");
	p1->print();

	programmer *p2 = new adv_programmer;
	p2->Set(1200, 18, "zhangwei");
	p2->print();

	programmer *p3 = new architect;
	p3->Set(1200, 18, "zhangwei");
	p3->print();
}
int main()
{
	test01();

	system("pause");
	return 0;
}
