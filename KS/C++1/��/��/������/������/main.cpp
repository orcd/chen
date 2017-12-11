#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

#include "Student.h"
#include "Graduate.h"

// ��һ��
/*	a) ���������� char *, Ҫ����MyString�Ķ����Ա
	b) ����ʹ��ȫ�ֱ�������static��Ա����
	c) ��Ա����Ӧ����˽�У�ͨ�����нӿڷ���
	d) ��дmain�������в��ԣ�
	����磺
	ѧ�� 	����    �ɼ�
	1		��XX		98
	2		��XX		90
	3		XXX		89
	ƽ���ɼ���	XX
*/

// ��һ�ڶ��� ��ӡ�ӿ�
void printStu(Student *stu[], int len) {
	for (int i = 0; i < len; i++)
	{
		// cout << *stu[i] << endl;
		stu[i]->display();

	}
}

// ��һ�ڶ��� �ͷŽӿ�
void freeStu(Student *stu[], int len) {
	for (int i = 0; i < len; i++)
	{
		delete stu[i];
	}

}

void test01() {
	Student *stu[6];
	stu[0] = new Student (1, "����", 80);
	stu[1] = new Student (2, "����", 76);
	stu[2] = new Student (3, "����", 96);
	stu[3] = new Student (4, "����", 89);
	stu[4] = new Student (5, "����", 67);
	stu[5] = new Student (6, "Maker", 99);

	cout << "ѧ��"<< '\t'<< "����" << '\t' << "�ɼ�" << '\t' << endl;
	printStu(stu, 6);
	cout << "ƽ���ɼ���	" << Student::getAvgScore() << endl;
	freeStu(stu, 6);

}

// 2����1�е�ѧ����������һ���о�����(Graduate)���о�����ѧ�����һ����ʦ��Ϣ����ʦ������	�����ļ���̣�
void test02() {

	Student *stu[6];
	stu[0] = new Graduate(1, "����", 80, "����ʦ");
	stu[1] = new Graduate(2, "����", 76, "����ʦ");
	stu[2] = new Graduate(3, "����", 96, "����ʦ");
	stu[3] = new Graduate(4, "����", 89, "����ʦ");
	stu[4] = new Graduate(5, "����", 67, "����ʦ");
	stu[5] = new Graduate(6, "Maker", 99, "����ʦ");

	cout << "ѧ��" << '\t' << "����" << '\t' << "�ɼ�" << '\t' << "��ʦ��" << '\t' << endl;
	printStu(stu, 6);

	cout << "ƽ���ɼ���	" << Student::getAvgScore() << endl;

	freeStu(stu, 6);

}

// 3����дһ��C++����, �������Ա( programmer )���ʣ�programmer����Ϊ����ӿ��ࡣs
class programmer
{
public:
	virtual int getSal() = 0;

};

// ��������Ա
class junior_programmer : public programmer
{
public:
	junior_programmer(int sal, int age, char *name){

		strcpy(this->name, name);
		this->age = age;
		this->sal = sal;
	}

	virtual int getSal()
	{
		cout << this->name << " " << this->age << " : " << this->sal << " -- ��������Ա" << endl;
		return 0;
	}

private:
	int sal;
	int age;
	char name[128];
};

// �м�����Ա
class mid_programmer : public programmer
{
public:
	mid_programmer(int sal, int age, char *name) {

		strcpy(this->name, name);
		this->age = age;
		this->sal = sal;
	}

	virtual int getSal()
	{
		cout << this->name << " " << this->age << " : " << this->sal << " -- ��������Ա" << endl;
		return 0;
	}

private:
	int sal;
	int age;
	char name[128];
};

// �߼�����Ա
class adv_programmer : public programmer
{
public:
	adv_programmer(int sal, int age, char *name) {

		strcpy(this->name, name);
		this->age = age;
		this->sal = sal;
	}

	virtual int getSal()
	{
		cout << this->name << " " << this->age << " : " << this->sal << " -- ��������Ա" << endl;
		return 0;
	}

private:
	int sal;
	int age;
	char name[128];
};

// �ܹ�ʦ
class architect : public programmer
{
public:
	architect(int sal, int age, char *name) {

		strcpy(this->name, name);
		this->age = age;
		this->sal = sal;
	}

	virtual int getSal()
	{
		cout << this->name << " " << this->age << " : " << this->sal << " -- ��������Ա" << endl;
		return 0;
	}

private:
	int sal;
	int age;
	char name[128];
};

//���㺯�� �򵥵Ŀ��
void printProSal(programmer *program)
{
	program->getSal();
}

void test03() {

	junior_programmer p1(8000, 20, "����");
	mid_programmer p2(1200, 24, "����");
	adv_programmer p3(1600, 28, "����");
	architect p4(50000, 35, "����");

	printProSal(&p1);
	printProSal(&p2);
	printProSal(&p3);
	printProSal(&p4);

}

// ������MyString����
void test04() {
	MyString str1; 
	MyString str2(10);
	MyString str3("����");
	MyString str4(str3);
	MyString str5;

	// �����ַ���������ſ�����
	cout << "�������ַ������в���:";
	cin >> str5;

	for (int i = 0; i < str5.length(); i++)
	{
		putchar(str5[i]);
		putchar(',');
	}
	cout << endl << endl;

	cout << "str1 " << str1 << endl;
	cout << "str2 " << str2 << endl;
	cout << "str3 " << str3 << endl;
	cout << "str4 " << str4 << endl;
	cout << "str5 " << str5 << endl << endl;

	cout << "str3 == str4 result: " << (str3 == str4) << endl;
	cout << "str3 != str4 result: " << (str3 != str4) << endl;
	cout << "str3 == str5 result: " << (str3 == str5) << endl;
	cout << "str3 != str5 result: " << (str3 != str5) << endl << endl;

	str1 = "����";
	str2 = str5;
	cout << "str1 char��ֵ " << str1 << endl;
	cout << "str2 ����ֵ " << str2 << endl;


}

// �㷨ʵ��  {0��1��2��3��4��5��6��7��8��9��10��11��.......  20}  ���ӡ���Ե��Ӽ� ����д���ļ�
void test05() {
	// �ļ�
	FILE *path = fopen("��������.txt", "wb");
	if (NULL == path) {
		cout << "�ļ�д��ʧ��" << endl;
		return;
	}

	// ��������
	int len = pow(2, 21);
	cout << "���ݳ���" << len <<"����д�����ݣ������ĵȴ�������" << endl;
	for (int i = 0; i < len; ++i)
	{
		fputc('{', path);
		int num = 0;
		for (int j = i, k = 0; j > 0; ++k) {
			if (j % 2 == 1) {
				if(num > 0)
					fputc(',', path);

				if (k >= 20) {
					fputs("20", path);
				}
				else if (k >= 10) {
					fputc('1', path);
					fputc('0' + k % 10, path);
				}
				else
				{
					fputc('0' + k , path);	
				}
				num = 1;
			}
			
			j /= 2;
		}
		fputc('}', path);
		fputc('\n', path);
	}

	if (NULL != path) {
		fclose(path);
	}
	cout << "д�������鿴����������.txt" << endl;
}

int main(void)
{
	cout << "================== ��һ�� ѧ�� ===================" << endl << endl;
	test01();

	cout << endl << "================== �ڶ���     �о��� ==================" << endl << endl;
	test02();

	cout << endl << "================== ������     �������Ա( programmer )���� ==================" << endl << endl;
	test03();

	cout << endl << "================== ������     MyString==================" << endl << endl;
	test04();

	cout << endl << "================== ������     ���� ==================" << endl << endl;
	test05();

	system("pause");
	return EXIT_SUCCESS;
}
