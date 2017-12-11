#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyString
{
public:
	friend ostream& operator<<(ostream &out, const MyString &str);
	friend istream& operator>>(istream &in, MyString &str);
public:
	MyString();
	MyString(const char *str);
	MyString(const MyString &str);
	~MyString();

	//赋值运算符重载
	MyString& operator=(const MyString &str);
	MyString& operator=(const char* str);
	//[]
	char& operator[](int pos);
	//+
	MyString operator+(const MyString &str);
	MyString operator+(const char* str);
	//==
	bool operator==(const MyString &str);
	//!=
	bool operator!=(const MyString &str);
	//
	void show();
private:
	char *m_str;
	int m_size;
	int m_capacity;
};

//默认构造
MyString::MyString()
{
	m_str = new char[10];
	memset(m_str, 0, 10);
	m_size = 0;
	m_capacity = 10;
}
//有参构造
MyString::MyString(const char *str)
{
	m_size = strlen(str);
	m_str = new char[m_size + 1];
	strcpy(m_str, str);
	m_capacity = m_size;
}
//拷贝构造
MyString::MyString(const MyString &str)
{
	this->m_size = str.m_size;
	this->m_str = new char[this->m_size + 1];
	strcpy(this->m_str, str.m_str);
	m_capacity = m_size;
}
//析构函数
MyString::~MyString()
{
	if (NULL != m_str)
	{
		delete[]m_str;
		m_str = NULL;
	}
}
//<<
ostream& operator<<(ostream &out, const MyString &str)
{
	out << str.m_str;
	return out;
}
//>>
istream& operator>>(istream &in, MyString &str)
{
	char temp[1024];
	in >> temp;
	if (NULL != str.m_str)
	{
		delete[]str.m_str;
	}
	str.m_size = strlen(temp);
	str.m_str = new char[str.m_size + 1];
	strcpy(str.m_str, temp);
	return in;
}
//=赋值运算符重载
MyString& MyString::operator=(const MyString &str)
{
	if (NULL != this->m_str)
	{
		delete[]m_str;
	}
	this->m_size = str.m_size;
	this->m_str = new char[this->m_size + 1];
	strcpy(this->m_str, str.m_str);

	m_capacity = m_size;
	return *this;
}
MyString& MyString::operator=(const char* str)
{
	if (NULL != this->m_str)
	{
		delete[]m_str;
	}
	this->m_size = strlen(str);
	this->m_str = new char[this->m_size + 1];
	strcpy(this->m_str, str);

	m_capacity = m_size;
	return *this;
}
//[]
char& MyString::operator[](int pos)
{
	return this->m_str[pos];
}
//+
MyString MyString::operator+(const MyString &str)
{
	int newSize = this->m_size + str.m_size;
	char *temp = new char[newSize + 1];
	memset(temp, 0, newSize + 1);
	if (NULL != this->m_str)
		strcat(temp, this->m_str);
	strcat(temp, str.m_str);
	MyString newStr(temp);

	m_capacity = m_size;
	return newStr;
}
MyString MyString::operator+(const char* str)
{
	int newSize = this->m_size + strlen(str);
	char *temp = new char[newSize + 1];
	memset(temp, 0, newSize + 1);
	if (NULL != this->m_str)
		strcat(temp, this->m_str);
	strcat(temp, str);
	MyString newStr(temp);

	m_capacity = m_size;
	return newStr;
}
//==
bool MyString::operator==(const MyString &str)
{
	if (0 == strcmp(this->m_str, str.m_str))
		return true;
	else
		return false;
}
//!=
bool MyString::operator!=(const MyString &str)
{
	if (0 != strcmp(this->m_str, str.m_str))
		return true;
	else
		return false;
}
//
void MyString::show()
{
	cout << "this is MyString." << endl;
}

void test01()
{
	//有参构造
	MyString str1("hello world.");
	//重载<<
	cout << str1 << endl;

	//重载>>
	cin >> str1;
	cout << str1 << endl;

	//拷贝构造
	MyString str2(str1);
	cout << str2 << endl;

	////赋值运算符重载
	MyString str3;
	str3 = str1;
	str3 = "abcd";
	cout << str3 << endl;

	////[]
	//cout << str1[2] << endl;

	////+
	MyString str4;
	cout << str4 + str1 << endl;
	cout << str4 + "123" << endl;
	cout << str1 + "123" << endl;

	//==
	MyString str5("hello world,.");
	if (str5 == str1)
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "not equal" << endl;
	}
	MyString *pStr = new MyString("hello world");
	cout << *pStr << endl;
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}