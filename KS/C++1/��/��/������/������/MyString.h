#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyString
{
public:
	//构造和析构
	MyString(int tmpLen = 0);
	MyString(const char *p);
	MyString(const MyString &obj);
	~MyString();

	//普通成员函数
	void display() const;
	char * c_str() const;
	int length(); //获取字符串长度

				  //运算符重载
				  // >> << 重载，友元函数
	friend istream &operator >> (istream &cin, MyString &obj);
	friend ostream &operator<<(ostream &cout, MyString &obj);

	// =, [] 重载
	MyString & operator=(const MyString &obj);
	MyString & operator=(const char *p);
	char &operator[](int index);

	// ==, != 重载
	bool operator==(const char *p);
	bool operator!=(const char *p);
	bool operator==(MyString &obj);
	bool operator!=(MyString &obj);

private:
	char *str;
	int len;
};

