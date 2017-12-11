
#include "stdio.h"
#define N 35
struct student
{
    int num;       //学号
    char name[8];      //姓名
    int nannv;     //性别
    int chines;        //语文成绩
    int math;      //数学成绩
    int English;   //英语成绩
    int physics;   //物理成绩
    int sum;       //总分
    double avr;        //平均分
}stu[N];

void input(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        int sum=0;
        double avr=0.0;
        printf("请输入第%d个学生信息\n",i+1);
        printf("请输入姓名");
        scanf("%s",&stu[i].name);
        printf("请输入学号 性别(0男1女) 语文 数学 英语 物理中间逗号分隔:");
        scanf("%d,%d,%d,%d,%d,%d,",&stu[i].num,&stu[i].nannv,&stu[i].chines,&stu[i].math,&stu[i].English,&stu[i].physics);
       
        stu[i].sum = stu[i].chines+stu[i].math+stu[i].English+stu[i].physics;
        stu[i].avr = (double)(stu[i].sum*1.0/4);
    }
}

void output(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("------------------------------------------------------------------\n");
        printf("第%d名：\n",i+1);
        printf("学号：%d\t\t姓名：%s\t\t性别：%d\n",stu[i].num,stu[i].name,stu[i].nannv);
        printf("语文成绩：%d\t数学成绩：%d\t英语成绩：%d\t物理成绩：%d\n",
            stu[i].chines,stu[i].math,stu[i].English,stu[i].physics);
        printf("总分：%d\t\t\t平均分：%.2f\n",stu[i].sum,stu[i].avr);
        printf("------------------------------------------------------------------\n");
    }
}

void sort(int n)
{
    int i,j;
    struct student st;
    //冒泡排序
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(stu[j].sum<stu[j+1].sum)
            {
                st = stu[j];
                stu[j] = stu[j+1];
                stu[j+1] = st;
            }
        }
    }
}
void main()
{
    int n;
    printf("请输入学生人数：");
    scanf("%d",&n);
    input(n);       //输入学生信息
    sort(n);        //按总成绩排序
    printf("排名信息如下：\n");
    output(n);      //输出学生信息
}
