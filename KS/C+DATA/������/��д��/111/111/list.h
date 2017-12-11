

/*
用C语言实现一个单链表，结点数据域为int数据类型。功能如下：
a) 创建一个单链表，数据域分别为3、1、10、7、6、5
b)删除链表中数据为6的节点；
c)在数据为3的后面添加一个节点，数据域为9；
d) 销毁链表。
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

//初始化
list * InitList();
// 按数据插入
void InsertByData(list * a, int b,int c);
// 删除一个节点
void DelByData(list *a, int b);
//销毁
void DestoryList(list *a);
//遍历
void ForEach(list *a);