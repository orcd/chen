

/*
��C����ʵ��һ�����������������Ϊint�������͡��������£�
a) ����һ��������������ֱ�Ϊ3��1��10��7��6��5
b)ɾ������������Ϊ6�Ľڵ㣻
c)������Ϊ3�ĺ������һ���ڵ㣬������Ϊ9��
d) ��������
*/
typedef struct _listnode
{
	int  data;
	struct _listnode *next;

}node;

typedef struct _list
{
	int  size;
	struct _listnode * head;
}list;

//��ʼ��
list * InitList();
// �����ݲ���
void InsertByData(list * a, int b,int c);
// ɾ��һ���ڵ�
void DelByData(list *a, int b);
//����
void DestoryList(list *a);
//����
void ForEach(list *a);