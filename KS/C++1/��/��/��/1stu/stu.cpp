#include "stu.h"

int stu::num = 0;
double stu::totalscore = 0.0;

stu::stu(MyString name, int id, double score)
{
	this->name = name;
	this->id = id;
	this->score = score;
	num++;
	totalscore += score;
}

MyString stu::getname()
{
	return this->name;
}

int stu::getid()
{
	return this->id;
}

double stu::getscore()
{
	return this->score;
}

double stu::avrscore()
{
	return totalscore /num;
}

