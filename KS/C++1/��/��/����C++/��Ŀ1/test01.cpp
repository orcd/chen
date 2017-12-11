
#include "test01.h"
MyString::MyString()
{
	this->name = new char[1];
	name[0] = '\0';
}
MyString::MyString(char *name)
{
	this->name = new char[strlen(name) + 1];
	memset(this->name, 0, strlen(name) + 1);
	strcpy(this->name, name);
}
MyString::MyString(MyString &str)
{
	if (this->name != NULL)
	{
		delete[] this->name;
		this->name = NULL;
	}
	int len = strlen(str.getName());
	this->name = new char[len + 1];
	memset(this->name, 0, len + 1);
	strcpy(this->name, str.getName());
}
char *MyString::getName()
{
	return this->name;
}
void MyString::setName(char *name)
{
	if (this->name != NULL)
	{
		delete[] this->name;
		this->name = NULL;
	}
	this->name = new char[strlen(name) + 1];
	memset(this->name, 0, strlen(name) + 1);
	strcpy(this->name, name);
}
MyString::~MyString()
{
	if (this->name != NULL)
	{
		delete[] this->name;
		this->name = NULL;
	}
}


void Student::setName(char *name)
{
	this->name.setName(name);
}
void Student::setID(int id)
{
	this->ID = id;
}
void Student::setScore(int score)
{
	this->score = score;
}

Student::~Student()
{

}