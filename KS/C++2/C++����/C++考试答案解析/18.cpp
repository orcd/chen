#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//请写出一个Cat类和Dog类继承与Animal类, 并封装一个架构函数实现多态，并写出测试案例。

//	class Animal
//	{
//	public:
//		Animal();
//		virtual void voice() = 0;
//	};


class Animal
{
public:
	Animal(){};
	virtual ~Animal(){};			// 为什么虚析构？ 基类没有虚析构，会导致子类没有调用析构函数
									// 虚析构函数是为了解决基类的指针指向派生类对象，并用基类的指针删除派生类对象。
	virtual void voice() = 0;
};

class Dog : public Animal{			//狗类继承Animal
public:
	virtual void voice(){
		cout << "汪汪汪..." << endl;
	}
};

class Cat : public Animal{			//猫类继承Animal
public:
	virtual void voice(){
		cout << "喵喵喵..." << endl;
	}
};

void DoBussiness(Animal& animal){
	animal.voice();
}

void test(){
	Cat cat;
	Dog dog;
	DoBussiness(dog);
	DoBussiness(cat);
}

int main(){
	test();
	system("pause");
	return EXIT_SUCCESS;
}