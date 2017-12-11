#include "mystring.h"

MyString::MyString(int tmpLen /*= 0*/)
{
	if (tmpLen == 0)
		this->str = NULL;
	else
		this->str = new char[tmpLen];
	this->len = tmpLen;

}

MyString::MyString(const char *p)
{
	if (p == NULL)
	{
		this->str = NULL;
		this->len = 0;
	}
	else
	{
		this->len = strlen(p)+1;
		this->str = new char[this->len];
		strcpy(this->str, p);
	}
}

MyString::MyString(const MyString &obj)
{
	if (this->str == obj.str)
		return ;
	this->len = obj.len;
	if (!this->str)
		delete[] this->str;
	this->str = new char[this->len];
	strcpy(this->str, obj.str);
}

MyString::~MyString()
{
	this->len = 0;
	if (!this->str)
		delete[] this->str;
	this->str = NULL;
}

void MyString::display() const
{
	cout << "str =" << this->str << ",len=" << this->len << endl;
}

char * MyString::c_str() const
{
	return this->str;
}

int MyString::length()
{
	return this->len;
}



char & MyString::operator[](int index)
{
	return str[index];
}

MyString & MyString::operator=(const char *p)
{
	if (this->str == p)
		return *this;
	if (this->str != NULL)
	{
		delete[] this->str;
		this->str = NULL;
		this->len = 0;
	}
	this->len = strlen(p)+1;
	this->str = new char[this->len];
	if (this->str != NULL)
	{
		strcpy(this->str, p);
	}
	return *this;
}

MyString & MyString::operator=(const MyString &obj)
{
	return this->operator=(obj.str);
}

bool MyString::operator==(const char *p)
{
	if (strcmp(p, this->str))
		return true;
	return false;
}

bool MyString::operator!=(const char *p)
{
	if (strcmp(p, this->str))
		return false;
	return true;
}

bool MyString::operator==(MyString &obj)
{
	return this->operator==(obj.str);
}

bool MyString::operator!=(MyString &obj)
{
	return this->operator!=(obj.str);
}

istream &operator>>(istream &cin, MyString &obj)
{
	MyString temp(1024);
	cin >> temp.str;
	obj.len = strlen(temp.str) + 1;
	if (obj.str != NULL)
		delete[] obj.str;
	obj.str = new char[obj.len];
	strcpy(obj.str, temp.str);
	return cin;
}

ostream &operator<<(ostream &cout, MyString &obj)
{
	cout << obj.str;
	return cout;
}