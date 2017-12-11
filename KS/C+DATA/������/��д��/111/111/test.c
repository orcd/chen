
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void test()
{
	list * newlist = InitList();

	node * a = malloc(sizeof(node));
	node * b = malloc(sizeof(node));
	node * c = malloc(sizeof(node));
	node * d = malloc(sizeof(node));
	node * e = malloc(sizeof(node));
	node * f = malloc(sizeof(node));
	a->next = b;
	a->data = 3;
	b->next = c;
	b->data = 1;
	c->next = d;
	c->data = 10;
	d->next = e;
	d->data = 7;
	e->next = f;
	e->data = 6;
	f->next = NULL;
	f->data = 5;
	newlist->size = 6;

	newlist->head = a;
	ForEach(newlist);
	DelByData(newlist,6);
	ForEach(newlist);
	InsertByData(newlist, 3, 9);
	ForEach(newlist);
	DestoryList(newlist);
	//ForEach(newlist);
}

int main()
{
	test();

	system("pause");
	return 0;
}