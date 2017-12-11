#include "MyString.h"

//���������
MyString::MyString(int tmpLen) {
	this->len = tmpLen;
	// ����ѿռ�
	this->str = new char[this->len + 1];
	for (int i = 0; i <= this->len; i++)
	{
		// ��ʼ��
		this->str[i] = '\0';
	}
}

MyString::MyString(const char *p) {
	this->len = strlen(p);
	// ����ѿռ�
	this->str = new char[this->len + 1];
	strcpy(this->str, p);
}

MyString::MyString(const MyString &obj) {
	this->len = obj.len;
	// ����ѿռ�
	this->str = new char[this->len + 1];
	strcpy(this->str, obj.str);
}

MyString::~MyString() {
	if (NULL != this->str) {
		delete[] this->str;
		this->str = NULL;
	}
}


//��ͨ��Ա����
void MyString::display() const {
	cout << this->str << endl;
}

char * MyString::c_str() const {
	return this->str;
}

int MyString::length() {
	return this->len;
}
//��ȡ�ַ�������

			  //���������
			  // >> << ���أ���Ԫ����
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


// =, [] ����
MyString & MyString::operator=(const MyString &obj) {
	// �ͷ�ԭ�пռ�
	if (NULL != this->str) {
		delete[] this->str;
		this->str = NULL;
	}
	this->len = obj.len;
	// ����ѿռ�
	this->str = new char[this->len + 1];
	strcpy(this->str, obj.str);
	return *this;
}

MyString & MyString::operator=(const char *p) {
	// �ͷ�ԭ�пռ�
	if (NULL != this->str) {
		delete[] this->str;
		this->str = NULL;
	}
	this->len = strlen(p);
	// ����ѿռ�
	this->str = new char[this->len + 1];
	strcpy(this->str, p);
	return *this;
}

char &MyString::operator[](int index) {
	// �ٳ���Χ�Ƿ���'\0'
	if (index < 0 || index > this->len)
		index = this->len;
	
	return this->str[index];
}


// ==, != ����
bool MyString::operator==(const char *p) {
	// ���Ȳ���ȷ���false
	if (this->len != strlen(p))
		return false;

	// �ж�����
	for (int i = 0; i < this->len; i++)
	{
		// ��һλ������򷵻�false
		if (this->str[i] != p[i])
			return false;
	}

	return true;
}

bool MyString::operator!=(const char *p) {
	return !(*this == p);
}

bool MyString::operator==(MyString &obj) {
	// ���Ȳ���ȷ���false
	if (this->len != obj.len)
		return false;

	// �ж�����
	for (int i = 0; i < this->len; i++)
	{
		// ��һλ������򷵻�false
		if (this->str[i] != obj.str[i])
			return false;
	}

	return true;
}

bool MyString::operator!=(MyString &obj) {
	return !(*this == obj);
}
