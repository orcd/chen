#pragma once
#include "MyString.h"
// ����ѧ�š��������ɼ�������ƽӿں������������Щѧ�����ݲ�����ƽ����
class Student
{
public:
	Student(int id, const char *name, int score = 0);
	virtual ~Student();

	void setId(int id);
	int getId();
	void setName(const char *p);
	const char *getName();
	void setScore(int score);
	int getScore();
	virtual void display();
	static double getAvgScore();

private:
	int id;// ѧ��
	MyString *name;
	int score;
	static int total_score;
	static int stu_num;

};

