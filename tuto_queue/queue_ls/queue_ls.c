#include <stdlib.h>
#include <stdio.h>
#include "queue_ls.h"

LsQuData NoneLsQuData = {-1, -1};

void initLsQueue(LsQueue *queue) {
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
}

int isLsQuEmpty(LsQueue *queue) {
	return queue->front == NULL;
}

LsQuNode *createLsQuNode(LsQuData data) {
	LsQuNode *node = (LsQuNode *) malloc(sizeof(LsQuNode));
	if (!node) {
		fprintf(stderr, "Memory allocation failed!!!\n");
		exit(-1);
	}
	node->data = data;
	node->next = NULL;
	return node;
}

void enLsQueue(LsQueue *queue, LsQuData data) {
	LsQuNode *node = createLsQuNode(data);
	if (isLsQuEmpty(queue)) {
		queue->front = node;
		queue->rear = node;
	} else {
		queue->rear->next = node;
		queue->rear = node;
	}
	queue->size++;
}

LsQuData deLsQueue(LsQueue *queue) {
	if (isLsQuEmpty(queue)) {
		fprintf(stderr, "Queue is empty\n");
		return NoneLsQuData;
	}

	LsQuNode *tmp = queue->front;
	LsQuData data = tmp->data;
	queue->front = tmp->next;
	if (queue->front == NULL) {
		queue->rear = NULL;
	}

	queue->size--;
	free(tmp);

	return data;
}

void freeLsQueue(LsQueue *queue) {
	while (!isLsQuEmpty(queue)) {
		deLsQueue(queue);
	}
}

void printLsQuNode(LsQuNode *node) {
	printf("%d\t%d\n", node->data.id, node->data.value);
}

void traverseLsQueue(LsQueue queue) {
	LsQuNode *p = queue.front;
	while (p != NULL) {
		printLsQuNode(p);
		p = p->next;
	}
}
