/*
2����1�е�ѧ����������һ���о�����(Graduate)���о�����ѧ�����һ����ʦ��Ϣ����ʦ������	�����ļ���̣�		15'
����ƽӿں�����������ʾ�о�����Ϣ������ ѧ�š��������ɼ�����ʦ��Ϣ��

����дmain�������в��ԣ�
����磺
ѧ�� 	����   	�ɼ�		��ʦ
1	  	��XX		98		��XX
2		��XX		90		XXX
3		XXX		89		XXX
ƽ���ɼ���	XX
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma  once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "mystring.h"
#include "stu.h"
using namespace std;

class graduate: virtual public stu
{
public:
	graduate(MyString  name, int id, double score, MyString teacher);
	void display();
	MyString getteacher();

protected: 
	MyString teacher;
};