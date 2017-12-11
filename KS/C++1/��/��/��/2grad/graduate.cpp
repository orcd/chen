#include "graduate.h"
graduate::graduate(MyString name, int id, double score, MyString teacher) :stu(name, id, score), teacher(teacher)
{
	
}

void graduate::display()
{
	cout << this->id << "\t" << this->name << "\t" << this->score << "\t" << this->teacher << endl;
}

MyString graduate::getteacher()
{
	return this->teacher;
}

