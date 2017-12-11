#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <cstdio>
class MyString
{
public:
	MyString();
	MyString(char *name);
	MyString(MyString &);
	char *getName();
	void setName(char *name);
	~MyString();
private:
	char *name;
};
class Student
{
public:
	Student()
	{
		ID = 0;
		score = 0;
	}
	Student(int id, char *name, int score)
	{
		this->name.setName(name);
		this->ID = id;
		this->score = score;
	}
	void setName(char *name);
	void setID(int id);
	void setScore(int score);
	char* getName(){ return name.getName(); }
	int getID(){ return ID; }
	int getscore(){ return score; }
	void printStu()
	{
		printf("%-8d%-8s%-8d\n", ID, name.getName(), score);
	}
	~Student();
private:
	MyString name;
	int ID;
	int score;
};
class Graduate :public Student
{
public:
	Graduate();
	Graduate(int id, char *name, int score, char* teacher);
	Graduate(Graduate& g);
	char *getTeacher()
	{
		//cout << Teacher.getName();
		return Teacher.getName();
	}
	void printGraduate()
	{
		printf("%-8d%-8s%-8d%-8s\n", getID(), getName(), getscore(), getTeacher());
	}
private:
	MyString Teacher;
};
