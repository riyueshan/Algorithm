/*
an implementation of linklist in chapter 3
presented by xdxu@ustc.edu.cn
*/

#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

//create a linklist with a head node
LinkList createLinkList(void) {
	LinkList L;
	L = (LinkList)malloc(sizeof(LinkNode));
	L->next = NULL;
	return L;
}

// get the ith element from the linklist
int getElem(LinkList L, int i, int *data) {
	LinkNode *p;
	int count;
	if (L==NULL) return -1;
	p = L->next;
	count = 0;
	while (p != NULL && count<i) {
		p = p->next;
		count++;
	}
	if (p==NULL || count>i) return -1;
	*data = p->data;
	return 0;	
}

// show elements in the linklist
void showLinkList(LinkList L) {
	LinkNode *p;
	if (L==NULL) {
		printf("LinkList does not exist.\n");
		return;
	}
	p = L->next;
	while (p!=NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");	
}

// insert an element before the ith node of the linklist
int insertElem(LinkList L, int i, int data) {
	LinkNode *p, *s;
	int count = 0;
	if (L==NULL) return -1;
	p = L;
	while (p!=NULL && count<i-1) {
		p = p->next;
		count++;
	}
	if (p==NULL || count>i) return -1;
	s = (LinkNode *)malloc(sizeof(LinkNode));
	s->data = data;
	s->next = p->next;
	p->next = s;
	return 0;
}

// delete the ith node in the linklist
int deleteElem(LinkList L, int i, int *data) {
	LinkNode *p, *q;
	int count = 0;
	if (L==NULL) return -1;
	p = L;
	while (p!=NULL && count<i-1) {
		p = p->next;
		count++;
	}
	if (p==NULL || count>i) return -1;
	q = p->next;
	p->next = q->next;
	*data = q->data;
	free(q);
	return 0;
} 

// destroy the existing linklist
void destroyLinkList(LinkList *L) {
	LinkNode *p, *q;
	if (*L==NULL) return;
	p = (*L)->next;
	while (p!=NULL) {
		q = p->next;
		free(p);
		p = q;
	}
	free(*L);
	*L = NULL;
}
