#include "Graduate.h"



Graduate::Graduate(int id, const char *name, int score, const char * teacher):Student(id, name, score)
{
	this->teacher = new MyString(teacher);
}


Graduate::~Graduate()
{

	if (NULL != this->teacher) {
		delete this->teacher;
	}
}

void Graduate::setTeacher(const char * teacher) {
	*this->teacher = teacher;
}

const char * Graduate::getTeacher() {
	return this->teacher->c_str();
}



void Graduate::display() {
	cout << this->getId() << '\t' << this->getName() << '\t' 
		<< this->getScore() << '\t' 
		<< this->getTeacher()<< '\t' << endl;
}