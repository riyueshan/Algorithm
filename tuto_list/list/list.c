//
// Created by riyueshan on 10/12/24.
//
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#include <time.h>

LsData HeadLsData = {0, 0};

LsData NoneLsData = {-1, -1};

void initList(LsNode **list) {
	*list = createLsNode(HeadLsData);
}

LsNode *createLsNode(LsData data) {
	LsNode *tmp = malloc(sizeof(LsNode));
	if (!tmp) {
		fprintf(stderr, "Memory allocation failed!!!\n");
		exit(-1);
	}

	tmp->data = data;
	tmp->next = NULL;
	return tmp;
}

void addLsNode(LsNode **list, LsData data) {
	LsNode *p = *list;
	LsNode *node = createLsNode(data);

	if (p == NULL) {
		*list = node;
		return;
	}

	while (p->next != NULL) {
		p = p->next;
	}
	p->next = node;
}

LsData removeLsNode(LsNode **list) {
	LsNode *p = *list;
	if (p == NULL) {
		return NoneLsData;
	}

	if (p->next == NULL) {
		LsData data = (*list)->data;
		*list = (*list)->next;
		free(p);
		return data;
	}

	LsNode *q = p->next;
	while (q->next != NULL) {
		p = p->next;
		q = p->next;
	}

	LsData data = q->data;
	p->next = NULL;
	free(q);

	return data;
}

void pushLsNode(LsNode **list, LsData data) {
	LsNode *node = createLsNode(data);

	if (*list == NULL) {
		*list = node;
		return;
	}

	node->next = *list;
	*list = node;
}

LsData popLsNode(LsNode **list) {
	if (*list == NULL) {
		return NoneLsData;
	}

	LsNode *tmp = *list;
	LsData data = (*list)->data;
	*list = (*list)->next;
	free(tmp);

	return data;
}

LsNode *locateSubList(LsNode *list, int id) {
	LsNode *p = list;
	while (p != NULL) {
		if (p->data.id == id) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

LsData deleteLsNode(LsNode **list, LsNode *out) {
	LsNode *p = *list;

	if (p == out) {
		LsData data = (*list)->data;
		*list = (*list)->next;
		free(p);
		return data;
	}

	LsNode *q = p->next;
	while (q != out && q != NULL) {
		p = p->next;
		q = p->next;
	}

	if (q == NULL) {
		return NoneLsData;
	}

	p->next = q->next;
	LsData data = q->data;
	free(q);

	return data;
}

void insertLsNode(LsNode **list, LsNode *prev, LsData data) {
	LsNode *node = createLsNode(data);

	if (prev == NULL) {
		node->next = *list;
		*list = node;
		return;
	}

	LsNode *p = *list;
	while (p != NULL) {
		if (p == prev) {
			node->next = p->next;
			p->next = node;
			return;
		}
		p = p->next;
	}
}

void traverseList(LsNode *list) {
	LsNode *p = list;
	while (p) {
		printLsNode(p);
		p = p->next;
	}
}

void printLsNode(LsNode *node) {
	printf("%d\t%d\n", node->data.id, node->data.value);
}


void freeList(LsNode **list) {
	while (*list) {
		removeLsNode(list);
	}
}
