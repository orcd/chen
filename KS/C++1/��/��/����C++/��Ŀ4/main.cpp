#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
	MyString s1("s1");
	MyString s2("s2");
	MyString s3;
	s3 = s1;
	s1.display();
	cout << s2;
	s3.display();
	MyString s4("s4");
	char *p = s4.c_str();
	s4.display();
	cout << "p=" << p << endl;
	cout << s1[1] << endl;

	MyString s5;
	cin >> s5;
	cout << s5;
	//system("pause");
	return 0;
}