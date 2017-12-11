
/*
假设一个student.txt文件,请你把文件中的信息读出，把每行的数据按age从大到小的顺序写入一个文件student2.txt中。
student文件请下载附件
提示：
(1) 每行的学生信息可用一个结构体进行保存。
typedef struct _tag_Student {
char name[24];
int age;
}Student;
(2) 获取从文件中读取的每一行学生的信息。
函数原型：int getStudentInfo(char *studentInfo, Student *stu);
函数功能：从studentInfo所指向的字符串中提取出学生的姓名年龄，并保存到一个结构体变量中。
函数参数：studentInfo：指向包含学生name和age的一个字符串。
stu：指向用于保存学生信息的结构体。
返回值：成功返回0，失败返回-1。
(3) 获得的每个学生的信息可用链表进行保存。
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
		printf("%d行的数据没有接收到\n", line);
		return NULL;
	}
	char * pname = strstr(buf, "name:");
	char * page = strstr(buf, "age:");
	stu *temp = (stu*)malloc(sizeof(stu));
	memset(temp, 0, sizeof(stu));
	if (  page==NULL || pname==NULL )
	{
		//printf("%d行的数据找不到age或者name\n", line);
		goto A;	
	}
	char * pf1 = NULL;//找:
	char * pf2 = NULL;//找,或者;
	pf1 = strstr(pname, ":");//name 后面的 :
	if (!pf1)
	{
		//printf("%d行name后面没有:\n", line);
		goto A;
	}
	pf2 = strstr(pname, ",");//name后面的 :
	if (!pf2)
	{
		//printf("%d行name后面没有,\n", line);
		goto A;
	}
	if (pf2<pf1 || pf2>page)
	{
		//printf("%d行name字符串格式错误\n", line);
		goto A;
	}
	char * name = pf1 + 1; //暂时可以知道的name可能的地址
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
	pf1 = strstr(page, ":");//age 后面的 :
	if (!pf1)
	{
		//printf("%d行age后面没有:\n", line);
		goto A;
	}
	pf2 = strstr(page, ";");//age后面的 :
	if (!pf2)
	{
		//printf("%d行age后面没有;\n", line);
		goto A;
	}
	if (pf2<pf1 )
	{
		//printf("%d行age字符串格式错误\n", line);
		goto A;
	}
	char * age = pf1 + 1; //暂时可以知道的age可能的地址
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

	printf("读取到数据%s:%d\n", temp->name, temp->age);
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
				pcur->next->ss = temp;//数据交换
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
		printf("链表不存在");
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
		//开辟新节点
		if (temp != NULL)
		{
			pcur = (node*)malloc(sizeof(node));
			pcur->ss =temp;
			pcur->next = NULL;
			//把链表节点串上去
			prev->next = pcur;
			prev = pcur;
		}	
	}
	FILE *b = fopen(filename2, "wb");
	ssort(ll);
	pcur =ll->head.next;
	//把链表的数据写入文件
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