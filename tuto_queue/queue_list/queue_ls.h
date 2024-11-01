#ifndef QUEUE_LS_H
#define QUEUE_LS_H

#include "data_queue.h"

void initLsQueue(LsQueue *queue);

int isLsQuEmpty(LsQueue *queue);

LsQuNode *createLsQuNode(LsQuData data);

void enLsQueue(LsQueue *queue, LsQuData data);

LsQuData deLsQueue(LsQueue *queue);

void freeLsQueue(LsQueue *queue);

void printLsQuNode(LsQuNode *node);

void traverseLsQueue(LsQueue queue);

#endif //QUEUE_LS_H
