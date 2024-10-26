//
// Created by riyueshan on 10/11/24.
//

#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

#include <stdbool.h>
#include "data.h"

typedef struct Node {
    // char status;
    Data data;
    struct Node *next;
} Node;

typedef Node *NodePtr;

typedef struct Lsqueue {
    NodePtr front;
    NodePtr rear;
    int size;
    int capacity;
} LsQueue;

typedef LsQueue *LsQueuePtr;

void initLsQueue(LsQueuePtr q, int capacity);

void destroyLsQueue(LsQueuePtr q);

// Status getFront(LsQueue q, NodePtr n);

bool isQueueFull(LsQueue q);

bool isQueueEmpty(LsQueue q);

void enQueue(LsQueuePtr queue, Node node);

void deQueue(LsQueuePtr queue, NodePtr nodeptr);

// bool search(LsQueuePtr q, Node n);

#endif //QUEUE_LIST_H
