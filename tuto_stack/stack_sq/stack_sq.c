#include <stdio.h>
#include <stdlib.h>
#include "stack_sq.h"

SqStData NoneSqStData = {-1,-1};

void initSqStack(SqStack *stack,int capacity) {

    stack->base = (SqStData *) malloc(capacity * sizeof(SqStData));
    if (!stack->base) {
        fprintf(stderr, "Memory allocation failed!!!\n");
        exit(-1);
    }

    stack->top = -1;
    stack->size = 0;
    stack->capacity = capacity;
}

int isSqStEmpty(SqStack stack) {
    return stack.base==NULL;
}

int isSqStFull(SqStack stack) {
    return stack.top == stack.capacity - 1;
}

void freeSqStack(SqStack *stack) {
    free(stack->base);
    stack->base = NULL;
    stack->top = -1;
    stack->size = 0;
};

SqStData popSqStack(SqStack *stack) {
    if(isSqStEmpty(*stack)) {
        fprintf(stderr,"SqStack is empty.\n");
        return NoneSqStData;
    }

    stack->size--;
    SqStData data = stack->base[stack->top];

    stack->base[stack->top]=NoneSqStData;
    stack->top--;

    return data;
};

void pushSqStack(SqStack *stack, SqStData data) {
    if (isSqStFull(*stack)) {
        fprintf(stderr, "SqStack is full.\n");
        return;
    }
    stack->base[++stack->top] = data;
    stack->size++;
}

void printSqStData(SqStData data) {
    printf("%d\t%d\n",data.id,data.value);
}

void traverseSqStack(SqStack stack) {
    for(int i=0;i<=stack.top;i++) {
        printSqStData(stack.base[i]);
    }
}

