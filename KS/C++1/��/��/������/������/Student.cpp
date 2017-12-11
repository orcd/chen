#include "Student.h"

Student::Student(int id, const char *name, int score) {
	this->id = id;
	this->name = new MyString(name);
	this->score = score;
	// 设置平均分
	this->total_score += this->score;
	++this->stu_num;
}

Student::~Student()
{
	if (NULL != this->name) {
		delete this->name;
		this->name = NULL;
	}
}

void Student::setId(int id) {
	this->id = id;
}

int Student::getId() {
	return this->id;
}

void Student::setName(const char *p) {
	*this->name = p;
}

const char *Student::getName() {
	return this->name->c_str();
}

void Student::setScore(int score) {
	// 设置平均分
	this->total_score += score - this->score;
	this->score = score;
}

int Student::getScore() {
	return this->score;
}

double Student::getAvgScore() {
	return (double)Student::total_score / Student::stu_num;
}

void Student::display() {
	cout << this->id << '\t' << *(this->name) << '\t' << this->score << '\t' << endl;
}


// 学生平均分初始化
int Student::total_score = 0;
int Student::stu_num = 0;

