#pragma once
#include "MyString.h"
// 包括学号、姓名、成绩，并设计接口函数用来输出这些学生数据并计算平均分
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
	int id;// 学号
	MyString *name;
	int score;
	static int total_score;
	static int stu_num;

};

