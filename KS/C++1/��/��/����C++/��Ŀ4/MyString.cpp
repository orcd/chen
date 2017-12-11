#include "MyString.h"

MyString::MyString(int tmpLen)
{
	len = tmpLen;
	str = new char[len + 1];
	memset(str, 0, len + 1);
}
MyString::MyString(const char *p)
{
	len = strlen(p);
	str = new char[len + 1];
	memset(str, 0, len + 1);
	strcpy(str, p);
}
MyString::MyString(const MyString &obj)
{
	if (str != NULL)
	{
		delete[] str;
		str = NULL;
	};
	len = obj.len;
	str = new char[len + 1];
	memset(str, 0, len + 1);
	strcpy(str, obj.str);
}
MyString::~MyString()
{
	if (str != NULL)
	{
		delete[] str;
		str = NULL;
	}
}
//普通成员函数
void MyString::display() const
{
	cout << "str=" << str << " len=" << len << endl;
}
char * MyString::c_str() const
{
	return str;
}
int MyString::length() //获取字符串长度
{
	return this->len;
}
//运算符重载
istream &operator>>(istream &cin, MyString &obj)
{
	cout << "请输入字符串长度:";
	cin >> obj.len;
	if (obj.str != NULL)
	{
		delete[] obj.str;
		obj.str = NULL;
	};
	obj.str = new char[obj.len + 1];
	memset(obj.str, 0, obj.len + 1);

	cout << "请输入字符串:";
	cin >> obj.str;
	return cin;
}
ostream &operator<<(ostream &cout, MyString &obj)
{
	cout << "str=" << obj.str << " len=" << obj.len << endl;
	return cout;
}

MyString & MyString::operator=(const MyString &obj)
{
	if (this->str != NULL)
	{
		delete[] this->str;
		this->str = NULL;
	}
	this->len = obj.len;
	this->str = new char[len + 1];
	memset(str, 0, len + 1);
	strcpy(str, obj.str);
	return *this;
}
MyString & MyString::operator=(const char *p)
{
	if (this->str != NULL)
	{
		delete[] this->str;
		this->str = NULL;
	}
	this->len = strlen(p);
	this->str = new char[len + 1];
	memset(str, 0, len + 1);
	strcpy(str, p);
	return *this;
}
char &MyString::operator[](int index)
{
	
	return str[index];
}

bool MyString::operator==(const char *p)
{
	if (strcmp(str, p) == 0)
	{
		return 1;
	}
	else
		return 0;
}
bool MyString::operator!=(const char *p)
{
	if (strcmp(str, p) != 0)
	{
		return 1;
	}
	else
		return 0;
}
bool MyString::operator==(MyString &obj)
{
	if (strcmp(str, obj.str) == 0)
	{
		return 1;
	}
	else
		return 0;
}
bool MyString::operator!=(MyString &obj)
{
	if (strcmp(str, obj.str) != 0)
	{
		return 1;
	}
	else
		return 0;
}