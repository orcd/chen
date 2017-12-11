#include "MyString.h"

//构造和析构
MyString::MyString(int tmpLen) {
	this->len = tmpLen;
	// 分配堆空间
	this->str = new char[this->len + 1];
	for (int i = 0; i <= this->len; i++)
	{
		// 初始化
		this->str[i] = '\0';
	}
}

MyString::MyString(const char *p) {
	this->len = strlen(p);
	// 分配堆空间
	this->str = new char[this->len + 1];
	strcpy(this->str, p);
}

MyString::MyString(const MyString &obj) {
	this->len = obj.len;
	// 分配堆空间
	this->str = new char[this->len + 1];
	strcpy(this->str, obj.str);
}

MyString::~MyString() {
	if (NULL != this->str) {
		delete[] this->str;
		this->str = NULL;
	}
}


//普通成员函数
void MyString::display() const {
	cout << this->str << endl;
}

char * MyString::c_str() const {
	return this->str;
}

int MyString::length() {
	return this->len;
}
//获取字符串长度

			  //运算符重载
			  // >> << 重载，友元函数
istream &operator >> (istream &cin, MyString &obj) {
	obj.str = new char[1024];
	cin >> obj.str;
	obj.len = strlen(obj.str);
	return cin;
}

ostream &operator<<(ostream &cout, MyString &obj) {
	cout << obj.str;
	return cout;
}


// =, [] 重载
MyString & MyString::operator=(const MyString &obj) {
	// 释放原有空间
	if (NULL != this->str) {
		delete[] this->str;
		this->str = NULL;
	}
	this->len = obj.len;
	// 分配堆空间
	this->str = new char[this->len + 1];
	strcpy(this->str, obj.str);
	return *this;
}

MyString & MyString::operator=(const char *p) {
	// 释放原有空间
	if (NULL != this->str) {
		delete[] this->str;
		this->str = NULL;
	}
	this->len = strlen(p);
	// 分配堆空间
	this->str = new char[this->len + 1];
	strcpy(this->str, p);
	return *this;
}

char &MyString::operator[](int index) {
	// 操出范围是返回'\0'
	if (index < 0 || index > this->len)
		index = this->len;
	
	return this->str[index];
}


// ==, != 重载
bool MyString::operator==(const char *p) {
	// 长度不相等返回false
	if (this->len != strlen(p))
		return false;

	// 判断内容
	for (int i = 0; i < this->len; i++)
	{
		// 有一位不相等则返回false
		if (this->str[i] != p[i])
			return false;
	}

	return true;
}

bool MyString::operator!=(const char *p) {
	return !(*this == p);
}

bool MyString::operator==(MyString &obj) {
	// 长度不相等返回false
	if (this->len != obj.len)
		return false;

	// 判断内容
	for (int i = 0; i < this->len; i++)
	{
		// 有一位不相等则返回false
		if (this->str[i] != obj.str[i])
			return false;
	}

	return true;
}

bool MyString::operator!=(MyString &obj) {
	return !(*this == obj);
}
