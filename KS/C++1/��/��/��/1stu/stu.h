/*1�����һ��ѧ���࣬����ѧ�š��������ɼ�������ƽӿں������������Щѧ�����ݲ�����ƽ���֡������ļ���̣�		25'
a) ���������� char *, Ҫ����MyString�Ķ����Ա
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

#define  _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "mystring.h"
using namespace std;

class stu
{
public:
	stu(MyString  name, int id, double score);
	
	MyString getname();
	int getid();
	double getscore();

	static double avrscore();
private:
	MyString name;
	int id;
	double score;


	//��̬��Ա
	static int num;//����
	static double totalscore;
};