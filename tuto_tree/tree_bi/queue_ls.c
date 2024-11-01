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

QuNode *createQuNode(QuData data) {
	QuNode *p = malloc(sizeof(QuNode));
	p->data_qu = data;
	p->next = NULL;
	return p;
}

int isQueueEmpty(LsQueue queue) {
	return queue.front == NULL;
}

void enQueue(LsQueue *queue, QuNode *QuNode) {
	if (isQueueEmpty(*queue)) {
		queue->front = queue->rear = QuNode;
	} else {
		queue->rear->next = QuNode;
		queue->rear = QuNode;
	}
	queue->size++;
}

QuData deQueue(LsQueue *queue) {
	if (isQueueEmpty(*queue))
		return (QuData){0};

	// return the deleted data

	QuNode *temp = queue->front->next;
	QuData data = queue->front->data_qu;
	free(queue->front);
	queue->front = temp;
	if (!queue->front)
		queue->rear = NULL; // QuNode deleted is the last one
	queue->size--;
	return data;
}
