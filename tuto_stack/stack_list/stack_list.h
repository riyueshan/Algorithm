//
// Created by riyueshan on 10/11/24.
//

#ifndef STACK_LIST_H
#define STACK_LIST_H

#include "data.h"

typedef struct Node {
    Data data;
    struct Node *next;
} Node;

typedef Node *NodePtr;

// NOTE: node top
// redefine a stack structure to simplify the operate and logic
typedef struct Stack {
    NodePtr top;
    int len;
} Stack;

void initStack(Stack *stack);

void pushStack(Stack *stack, Data data);

Data popStack(Stack *stack);

Data topStack(Stack stack);

NodePtr getNode(const Stack *stack);

void clearStack(Stack *stack);

#endif // STACK_LIST_H
