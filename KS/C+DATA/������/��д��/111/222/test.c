
/*
����һ��student.txt�ļ�,������ļ��е���Ϣ��������ÿ�е����ݰ�age�Ӵ�С��˳��д��һ���ļ�student2.txt�С�
student�ļ������ظ���
��ʾ��
(1) ÿ�е�ѧ����Ϣ����һ���ṹ����б��档
typedef struct _tag_Student {
char name[24];
int age;
}Student;
(2) ��ȡ���ļ��ж�ȡ��ÿһ��ѧ������Ϣ��
����ԭ�ͣ�int getStudentInfo(char *studentInfo, Student *stu);
�������ܣ���studentInfo��ָ����ַ�������ȡ��ѧ�����������䣬�����浽һ���ṹ������С�
����������studentInfo��ָ�����ѧ��name��age��һ���ַ�����
stu��ָ�����ڱ���ѧ����Ϣ�Ľṹ�塣
����ֵ���ɹ�����0��ʧ�ܷ���-1��
(3) ��õ�ÿ��ѧ������Ϣ����������б��档
typedef struct _listNode {
Student *stu;
struct _listNode *next;
}ListNode;
*/

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define filename1 "./stu.txt"
#define filename2 "./stu2.txt"

typedef struct stu
{
	char name[12];
	int age;
}stu;
typedef struct listnode
{
	struct listnode * next;
	stu * ss;
}node;
typedef struct list
{
	node head;
}list;
static int line = 0;
stu * split(char *buf)
{
	//line++;
	if (buf == NULL)
	{
		printf("%d�е�����û�н��յ�\n", line);
		return NULL;
	}
	char * pname = strstr(buf, "name:");
	char * page = strstr(buf, "age:");
	stu *temp = (stu*)malloc(sizeof(stu));
	memset(temp, 0, sizeof(stu));
	if (  page==NULL || pname==NULL )
	{
		//printf("%d�е������Ҳ���age����name\n", line);
		goto A;	
	}
	char * pf1 = NULL;//��:
	char * pf2 = NULL;//��,����;
	pf1 = strstr(pname, ":");//name ����� :
	if (!pf1)
	{
		//printf("%d��name����û��:\n", line);
		goto A;
	}
	pf2 = strstr(pname, ",");//name����� :
	if (!pf2)
	{
		//printf("%d��name����û��,\n", line);
		goto A;
	}
	if (pf2<pf1 || pf2>page)
	{
		//printf("%d��name�ַ�����ʽ����\n", line);
		goto A;
	}
	char * name = pf1 + 1; //��ʱ����֪����name���ܵĵ�ַ
	while (*name == ' ')
	{
		name++;
	}
	while (*(pf2-1) == ' ')
	{
		pf2--;
	}
	if (name >= pf2 - 1)
	{
		goto A;
	}
	memcpy(temp->name, name, pf2 -name);
	pf1 = strstr(page, ":");//age ����� :
	if (!pf1)
	{
		//printf("%d��age����û��:\n", line);
		goto A;
	}
	pf2 = strstr(page, ";");//age����� :
	if (!pf2)
	{
		//printf("%d��age����û��;\n", line);
		goto A;
	}
	if (pf2<pf1 )
	{
		//printf("%d��age�ַ�����ʽ����\n", line);
		goto A;
	}
	char * age = pf1 + 1; //��ʱ����֪����age���ܵĵ�ַ
	while (*age == ' ')
	{
		age++;
	}
	while (*(pf2 - 1) == ' ')
	{
		pf2--;
	}
	if (age >= pf2 - 1)
	{
		goto A;
	}
	char num[8];
	memset(num, 0, 8);
	memcpy(num, pf1 + 1, pf2 - pf1 - 1);
	sscanf(num, "%d", &(temp->age));

	printf("��ȡ������%s:%d\n", temp->name, temp->age);
	return temp;
A:
	free(temp);
	return NULL;
}
void ssort(list * l)
{
	if (l == NULL)
	{
		return;
	}
	int flag = 0;
	do
	{
		flag = 0;
		node * pcur = l->head.next;
		while (pcur->next != NULL)
		{
			if (pcur->ss->age > pcur->next->ss->age)
			{
				stu * temp = pcur->ss;
				pcur->ss = pcur->next->ss;
				pcur->next->ss = temp;//���ݽ���
				flag = 1;
			}
			pcur = pcur->next;
		}
	} while (flag != 0);
}
void encode(stu * s, char * buf)
{
	if (s == NULL)
	{
		return;
	}
	sprintf(buf, "name:%s,age:%d\n", s->name, s->age);
	//printf("%s\n", buf);
}
void destoryList(list * l)
{
	if (l == NULL)
	{
		printf("��������");
	}
	node * pcur = l->head.next;
	node * ptemp = pcur;
	while (pcur != NULL)
	{
		ptemp = pcur->next;
		free(pcur);
		pcur = ptemp;
	}
	free(l);
	l = NULL;
}
void test()
{
	FILE * a = fopen(filename1, "rb");
	char buf[100];
	list * ll = (list *)malloc(sizeof(list));
	ll->head.next = NULL;
	node * prev = &(ll->head);
	node * pcur = NULL;
	while (!feof(a))
	{
		memset(buf, 0, 100);
		fgets(buf, 100, a);
		//printf("%s", buf);
		stu * temp = split(buf);
		//�����½ڵ�
		if (temp != NULL)
		{
			pcur = (node*)malloc(sizeof(node));
			pcur->ss =temp;
			pcur->next = NULL;
			//������ڵ㴮��ȥ
			prev->next = pcur;
			prev = pcur;
		}	
	}
	FILE *b = fopen(filename2, "wb");
	ssort(ll);
	pcur =ll->head.next;
	//�����������д���ļ�
	while (pcur != NULL)
	{
		memset(buf, 0, 100);
		encode(pcur->ss, buf);
		fputs(buf, b);
		pcur = pcur->next;
	}

	fclose(a);
	fclose(b);
	destoryList(ll);
}

int main()
{
	test();

	system("pause");
	return 0;
}