/*
an implementation of linklist in chapter 3
presented by xdxu@ustc.edu.cn
*/

#ifndef _LINKLIST_H_
#define _LINKLIST_H_

typedef struct LinkNode {
	int data;
	struct LinkNode *next;
}LinkNode, *LinkList;

//create a linklist with a head node
LinkList createLinkList(void);

// get the ith element from the linklist
int getElem(LinkList L, int i, int *data);

// show elements in the linklist
void showLinkList(LinkList L);

// insert an element before the ith node of the linklist
int insertElem(LinkList L, int i, int data);

// delete the ith node in the linklist
int deleteElem(LinkList L, int i, int *data);

// destroy the existing linklist
void destroyLinkList(LinkList *L);

#endif