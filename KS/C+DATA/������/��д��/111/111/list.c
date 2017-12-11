
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

list * InitList()
{
	list *a =(list*)malloc(sizeof(list));
	a->head = NULL;
	a->size = 0;
	return a;
}

void InsertByData(list * a, int b ,int c)
{
	node * pcur = a->head;
	for ( ; pcur != NULL; pcur = pcur->next)
	{
		if (pcur->data == b)
		{
			node * temp = (node *)malloc(sizeof(node));
			temp->data = c;
			temp->next = pcur->next;
			pcur->next = temp;
			a->size ++;
			break;
		}
	}
}

void DelByData(list *a, int b)
{
	node * pcur = a->head;
	node * prev = NULL;
	for (; pcur != NULL; pcur = pcur->next)
	{
		if (pcur->data == b)
		{
			if (pcur == a->head)
			{
				a->head = pcur->next;
			}
			else
			{
				prev->next = pcur->next;
			}
			free(pcur);
			pcur = NULL;
			a->size--;
			break;
		}
		prev = pcur;
	}
}

void DestoryList(list *a)
{
	node * pcur = a->head;
	node * prev = NULL;
	while (pcur)
	{
		prev = pcur;
		pcur = pcur->next;
		free(prev);
	}
	free(a);
	a = NULL;
}

void ForEach(list *a)
{
	node * pcur = a->head;
	for (; pcur != NULL; pcur = pcur->next)
	{
		printf("%d->", pcur->data);
	}
	printf("\n");
}
