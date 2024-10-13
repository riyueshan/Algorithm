#include <stdio.h>
#include <stdlib.h>

#include "stack_list.h"

void initStack(Stack *stack) {
    stack->top = NULL;
    stack->len = 0;
}

void pushStack(Stack *stack, Data data) {
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;

    stack->len++;
    if (stack->top == NULL) {
        stack->top = newNode;
        newNode->next = NULL;
        return;
    }

    newNode->next = stack->top;
    stack->top = newNode;
}

Data popStack(Stack *stack) {
    if (stack->top == NULL) {
        fprintf(stderr, "Stack is empty.\n");
        exit(1);
    }

    NodePtr temp = stack->top;
    Data data = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->len--;
    return data;
}

Data topStack(const Stack stack) {
    if (!stack.len) {
        fprintf(stderr, "Stack is empty.\n");
        return (Data){0};
    }
    return stack.top->data;
}

NodePtr getNode(const Stack *stack) {
    if (stack->len) {
        return stack->top;
    }

    return NULL;
}

void clearStack(Stack *stack) {
    while (stack->len) {
        popStack(stack);
    }
}
