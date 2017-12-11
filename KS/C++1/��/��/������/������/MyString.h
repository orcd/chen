#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyString
{
public:
	//���������
	MyString(int tmpLen = 0);
	MyString(const char *p);
	MyString(const MyString &obj);
	~MyString();

	//��ͨ��Ա����
	void display() const;
	char * c_str() const;
	int length(); //��ȡ�ַ�������

				  //���������
				  // >> << ���أ���Ԫ����
	friend istream &operator >> (istream &cin, MyString &obj);
	friend ostream &operator<<(ostream &cout, MyString &obj);

	// =, [] ����
	MyString & operator=(const MyString &obj);
	MyString & operator=(const char *p);
	char &operator[](int index);

	// ==, != ����
	bool operator==(const char *p);
	bool operator!=(const char *p);
	bool operator==(MyString &obj);
	bool operator!=(MyString &obj);

private:
	char *str;
	int len;
};

