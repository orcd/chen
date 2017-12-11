#pragma once
#include "Student.h"

class Graduate :public Student
{
public:
	Graduate(int id, const char *name, int score = 0, const char * teacher = NULL);
	virtual ~Graduate();

	virtual void display();

	void setTeacher(const char * teacher);
	const char * getTeacher();

private:
	MyString *teacher;
};

