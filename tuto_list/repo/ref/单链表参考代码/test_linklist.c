/*
test cases for linklist in chapter 3
presented by xdxu@ustc.edu.cn
*/

#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

LinkList mergeList(LinkList La, LinkList Lb) {
	LinkList Lc;
	LinkNode *pa, *pb, *pc;
	if (La == NULL) return Lb;
	if (Lb == NULL) return La;
	Lc = La;
	pa = La->next;
	pb = Lb->next;
	free(Lb);
	pc = Lc;
	while (pa!=NULL && pb!=NULL) {
		if (pa->data <= pb->data) {			
			pc->next = pa; 
			pc = pa;
			pa = pa->next;
		} else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		
	}
	if (pa!=NULL) pc->next = pa;
	else pc->next = pb;
	return Lc;
}

// reverse a linklist
void reverseLinkList(LinkList L) {
	LinkList R;
	LinkNode *last=NULL, *p, *q;
	if (L==NULL) return;
	p = L->next;
	while (p!=NULL) {
		q = p->next;
		p->next = last;
		last = p;
		p = q;
	}
	L->next = last;
}

// find the nth node from end
LinkNode* NthNodeFromEnd(LinkList L, int n) {
	LinkNode *p, *q;
	int count = 0;
	p = L->next;
	q = L->next;
	while (p!=NULL && count<n) {
		p = p->next;
		count++;
	}
	if (p==NULL) return NULL;
	while (p!=NULL) {
		p = p->next;
		q = q->next;
	}
	return q;	
}

// test cases
int main(void) {
	int arr[5] = {23, 15, 11, 4, 2};
	int list[8] = {37, 28, 22, 19, 15, 7, 6, 4};
	LinkList L, La, Lb;
	int i, data;
	LinkNode *p;
	
	//case-1: basic operations
	printf("case-1: basic operations...\n");
	L = createLinkList();
	for (i=0; i<5; i++) {
		insertElem(L, 1, arr[i]);
		showLinkList(L);
	}
	for (i=0; i<5; i++) {
		deleteElem(L, 1, &data);
		showLinkList(L);
	}
	destroyLinkList(&L);
	
	//case-2: merge two linklist
	printf("case-2: merge two linklist...\n");
	La = createLinkList();
	Lb = createLinkList();
	for (i=0; i<5; i++) {
		insertElem(La, 1, arr[i]);
	}
	showLinkList(La);
	for (i=0; i<8; i++) {
		insertElem(Lb, 1, list[i]);
	}
	showLinkList(Lb);
	L = mergeList(La, Lb);	
	showLinkList(L);
	
	//case-3: find the nth node from end
	printf("\ncase-3: find the nth node from end...\n");
	p = NthNodeFromEnd(L, 5);
	if (p!=NULL) printf("the nth node is %d.\n", p->data);
	
	//case-4: reverse a linklist
	printf("\ncase-4: reverse a linklist...\n");
	reverseLinkList(L);
	showLinkList(L);
	destroyLinkList(&L);
}