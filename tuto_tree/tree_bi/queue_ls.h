//
// Created by riyueshan on 10/11/24.
//

#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

#include "data_tree.h"

typedef struct Lsqueue
{
	QuNode *front;
	QuNode *rear;
	int size;
} LsQueue;

void initLsQueue(LsQueue *queue);

void freeLsQueue(LsQueue queue);

QuNode *createQuNode(QuData data);

int isQueueEmpty(LsQueue queue);

void enQueue(LsQueue *queue, QuNode *QuNode);

QuData deQueue(LsQueue* queue);

#endif // QUEUE_LIST_H
