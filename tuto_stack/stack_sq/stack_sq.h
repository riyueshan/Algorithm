#ifndef STACK_SEQUENTIAL_H
#define STACK_SEQUENTIAL_H

#include "../data_stack.h"

typedef struct SqStack {
	SqStData *base;
	int top;
	int capacity;
	int size;
} SqStack;


void initSqStack(SqStack *stack,int capacity);

int isSqStEmpty(SqStack stack);

int isSqStFull(SqStack stack);

void freeSqStack(SqStack *stack);

SqStData popSqStack(SqStack *stack);

void pushSqStack(SqStack *stack, SqStData data);

void printSqStData(SqStData data);

void traverseSqStack(SqStack stack);

#endif // STACK_SEQUENTIAL_H
