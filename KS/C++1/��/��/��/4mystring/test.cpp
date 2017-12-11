
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "mystring.h"
using namespace std;

void test()
{
	MyString a(10);
	MyString b("123");
	MyString c(b);
	b.display();
	cout << b.c_str() << "  len"<< b.length() <<endl;
	cout << b << endl;
	cin >> a;
	cout << a;
	MyString d("321");
	d.display();
	d = a;
	d = b.c_str();
	cout << d;
	cout << b[1];

	cout << (c == b) << endl;
	cout << (c == b.c_str()) << endl;


}

int main(int argc, char * argv[])
{
	test();

	system("pause");
	return 0;
}