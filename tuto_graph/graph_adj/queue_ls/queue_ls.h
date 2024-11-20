//
// Created by riyueshan on 10/11/24.
//

#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

#include "../../data_graph.h"
typedef struct LsQuData {
	ArcNode* node;
} LsQuData;

typedef struct LsQuNode {
	LsQuData data_qu;
	struct LsQuNode *next;
} LsQuNode;

typedef struct Lsqueue {
	LsQuNode *front;
	LsQuNode *rear;
	int size;
} LsQueue;

void initLsQueue(LsQueue *queue);

void freeLsQueue(LsQueue queue);

LsQuNode *createLsQuNode(LsQuData data);

int isQueueEmpty(LsQueue queue);

void enQueue(LsQueue *queue, LsQuNode *LsQuNode);

LsQuData deQueue(LsQueue *queue);

#endif // QUEUE_LIST_H
