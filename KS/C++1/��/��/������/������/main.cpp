#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

#include "Student.h"
#include "Graduate.h"

// 第一题
/*	a) 姓名不能是 char *, 要求是MyString的对象成员
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

// 第一第二题 打印接口
void printStu(Student *stu[], int len) {
	for (int i = 0; i < len; i++)
	{
		// cout << *stu[i] << endl;
		stu[i]->display();

	}
}

// 第一第二题 释放接口
void freeStu(Student *stu[], int len) {
	for (int i = 0; i < len; i++)
	{
		delete stu[i];
	}

}

void test01() {
	Student *stu[6];
	stu[0] = new Student (1, "张三", 80);
	stu[1] = new Student (2, "李四", 76);
	stu[2] = new Student (3, "王五", 96);
	stu[3] = new Student (4, "赵六", 89);
	stu[4] = new Student (5, "陈七", 67);
	stu[5] = new Student (6, "Maker", 99);

	cout << "学号"<< '\t'<< "姓名" << '\t' << "成绩" << '\t' << endl;
	printStu(stu, 6);
	cout << "平均成绩：	" << Student::getAvgScore() << endl;
	freeStu(stu, 6);

}

// 2、从1中的学生类派生出一个研究生类(Graduate)，研究生比学生多出一个导师信息（导师名），	（分文件编程）
void test02() {

	Student *stu[6];
	stu[0] = new Graduate(1, "张三", 80, "江老师");
	stu[1] = new Graduate(2, "李四", 76, "江老师");
	stu[2] = new Graduate(3, "王五", 96, "江老师");
	stu[3] = new Graduate(4, "赵六", 89, "刘老师");
	stu[4] = new Graduate(5, "陈七", 67, "刘老师");
	stu[5] = new Graduate(6, "Maker", 99, "刘老师");

	cout << "学号" << '\t' << "姓名" << '\t' << "成绩" << '\t' << "导师名" << '\t' << endl;
	printStu(stu, 6);

	cout << "平均成绩：	" << Student::getAvgScore() << endl;

	freeStu(stu, 6);

}

// 3、编写一个C++程序, 计算程序员( programmer )工资，programmer设置为抽象接口类。s
class programmer
{
public:
	virtual int getSal() = 0;

};

// 初级程序员
class junior_programmer : public programmer
{
public:
	junior_programmer(int sal, int age, char *name){

		strcpy(this->name, name);
		this->age = age;
		this->sal = sal;
	}

	virtual int getSal()
	{
		cout << this->name << " " << this->age << " : " << this->sal << " -- 初级程序员" << endl;
		return 0;
	}

private:
	int sal;
	int age;
	char name[128];
};

// 中级程序员
class mid_programmer : public programmer
{
public:
	mid_programmer(int sal, int age, char *name) {

		strcpy(this->name, name);
		this->age = age;
		this->sal = sal;
	}

	virtual int getSal()
	{
		cout << this->name << " " << this->age << " : " << this->sal << " -- 初级程序员" << endl;
		return 0;
	}

private:
	int sal;
	int age;
	char name[128];
};

// 高级程序员
class adv_programmer : public programmer
{
public:
	adv_programmer(int sal, int age, char *name) {

		strcpy(this->name, name);
		this->age = age;
		this->sal = sal;
	}

	virtual int getSal()
	{
		cout << this->name << " " << this->age << " : " << this->sal << " -- 初级程序员" << endl;
		return 0;
	}

private:
	int sal;
	int age;
	char name[128];
};

// 架构师
class architect : public programmer
{
public:
	architect(int sal, int age, char *name) {

		strcpy(this->name, name);
		this->age = age;
		this->sal = sal;
	}

	virtual int getSal()
	{
		cout << this->name << " " << this->age << " : " << this->sal << " -- 初级程序员" << endl;
		return 0;
	}

private:
	int sal;
	int age;
	char name[128];
};

//计算函数 简单的框架
void printProSal(programmer *program)
{
	program->getSal();
}

void test03() {

	junior_programmer p1(8000, 20, "张三");
	mid_programmer p2(1200, 24, "李四");
	adv_programmer p3(1600, 28, "王五");
	architect p4(50000, 35, "赵六");

	printProSal(&p1);
	printProSal(&p2);
	printProSal(&p3);
	printProSal(&p4);

}

// 第四题MyString测试
void test04() {
	MyString str1; 
	MyString str2(10);
	MyString str3("张三");
	MyString str4(str3);
	MyString str5;

	// 输入字符串测试请放开此行
	cout << "请输入字符串进行测试:";
	cin >> str5;

	for (int i = 0; i < str5.length(); i++)
	{
		putchar(str5[i]);
		putchar(',');
	}
	cout << endl << endl;

	cout << "str1 " << str1 << endl;
	cout << "str2 " << str2 << endl;
	cout << "str3 " << str3 << endl;
	cout << "str4 " << str4 << endl;
	cout << "str5 " << str5 << endl << endl;

	cout << "str3 == str4 result: " << (str3 == str4) << endl;
	cout << "str3 != str4 result: " << (str3 != str4) << endl;
	cout << "str3 == str5 result: " << (str3 == str5) << endl;
	cout << "str3 != str5 result: " << (str3 != str5) << endl << endl;

	str1 = "李四";
	str2 = str5;
	cout << "str1 char赋值 " << str1 << endl;
	cout << "str2 对象赋值 " << str2 << endl;


}

// 算法实现  {0，1，2，3，4，5，6，7，8，9，10，11，.......  20}  请打印所以的子集 ，并写入文件
void test05() {
	// 文件
	FILE *path = fopen("第五题结果.txt", "wb");
	if (NULL == path) {
		cout << "文件写入失败" << endl;
		return;
	}

	// 集合数量
	int len = pow(2, 21);
	cout << "数据长度" << len <<"正在写入数据，请耐心等待。。。" << endl;
	for (int i = 0; i < len; ++i)
	{
		fputc('{', path);
		int num = 0;
		for (int j = i, k = 0; j > 0; ++k) {
			if (j % 2 == 1) {
				if(num > 0)
					fputc(',', path);

				if (k >= 20) {
					fputs("20", path);
				}
				else if (k >= 10) {
					fputc('1', path);
					fputc('0' + k % 10, path);
				}
				else
				{
					fputc('0' + k , path);	
				}
				num = 1;
			}
			
			j /= 2;
		}
		fputc('}', path);
		fputc('\n', path);
	}

	if (NULL != path) {
		fclose(path);
	}
	cout << "写入完成请查看：第五题结果.txt" << endl;
}

int main(void)
{
	cout << "================== 第一题 学生 ===================" << endl << endl;
	test01();

	cout << endl << "================== 第二题     研究生 ==================" << endl << endl;
	test02();

	cout << endl << "================== 第三题     计算程序员( programmer )工资 ==================" << endl << endl;
	test03();

	cout << endl << "================== 第四题     MyString==================" << endl << endl;
	test04();

	cout << endl << "================== 第五题     集合 ==================" << endl << endl;
	test05();

	system("pause");
	return EXIT_SUCCESS;
}
