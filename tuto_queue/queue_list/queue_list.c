#include <stdio.h>
#include <stdlib.h>

#include "queue_list.h"

void initLsQueue(LsQueuePtr q, int capacity)
{
    if (!q)
        return;

    q->capacity = capacity;
    q->size = 0;
    q->front = q->rear = NULL;
}

void destroyLsQueue(LsQueuePtr q)
{
    if (!q)
        return;

    NodePtr p = q->front;
    while (p != NULL)
    {
        NodePtr r = p->next;
        free(p);
        p = r;
    }
    q->front = q->rear = NULL;
    q->size = 0;
}

bool isQueueFull(LsQueue q)
{
    return q.size == q.capacity;
}

bool isQueueEmpty(LsQueue q)
{
    return q.size == 0;
}

void enQueue(LsQueuePtr queue, const Node node)
{
    if (isQueueFull(*queue))
        return;

    NodePtr p = malloc(sizeof(Node));
    *p = node;
    p->next = NULL;

    if (isQueueEmpty(*queue))
    {
        queue->front = queue->rear = p;
    }
    else
    {
        queue->rear->next = p;
        queue->rear = p;
    }
    queue->size++;
}

void deQueue(LsQueuePtr queue, NodePtr nodeptr)
{
    if (isQueueEmpty(*queue))
        return;

    //return the deleted value
    *nodeptr = *queue->front;
    nodeptr->next = NULL;

    NodePtr temp = queue->front->next;
    free(queue->front);
    queue->front = temp;
    if (!queue->front)
        queue->rear = NULL; // node deleted is the last one
    queue->size--;
}

// bool search(LsQueuePtr q, Node n) {
//     if (isEmpty(*q)) {
//         return ;
//     }
//
//     NodePtr p = q->front;
//     while (p != NULL) {
//         if (p->num == n.num) {
//             return true;
//         }
//     }
//
//     return false;
// }
