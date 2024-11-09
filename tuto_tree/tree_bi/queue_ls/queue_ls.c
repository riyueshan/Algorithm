#include <stdio.h>
#include <stdlib.h>

#include "queue_ls.h"

void initLsQueue(LsQueue *queue) {
	queue->size = 0;
	queue->front = queue->rear = NULL;
}

void freeLsQueue(LsQueue queue) {
	while (!isQueueEmpty(queue)) {
		deQueue(&queue);
	}
}

LsQuNode *createLsQuNode(LsQuData data) {
	LsQuNode *p = malloc(sizeof(LsQuNode));
	p->data_qu = data;
	p->next = NULL;
	return p;
}

int isQueueEmpty(LsQueue queue) {
	return queue.front == NULL;
}

void enQueue(LsQueue *queue, LsQuNode *LsQuNode) {
	if (isQueueEmpty(*queue)) {
		queue->front = queue->rear = LsQuNode;
	} else {
		queue->rear->next = LsQuNode;
		queue->rear = LsQuNode;
	}
	queue->size++;
}

LsQuData deQueue(LsQueue *queue) {
	if (isQueueEmpty(*queue))
		return (LsQuData){0};

	// return the deleted data

	LsQuNode *temp = queue->front->next;
	LsQuData data = queue->front->data_qu;
	free(queue->front);
	queue->front = temp;
	if (!queue->front)
		queue->rear = NULL; // LsQuNode deleted is the last one
	queue->size--;
	return data;
}
