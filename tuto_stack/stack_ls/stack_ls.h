//
// Created by riyueshan on 10/11/24.
//

#ifndef STACK_LIST_H
#define STACK_LIST_H

#include "../data_stack.h"

typedef struct Stack {
	LsStNode* top;
	int size;
} LsStack;

void initLsStack(LsStack *stack);

LsStNode* createLsStNode(LsStData data);

int isLsStEmpty(LsStack stack);

void pushLsStack(LsStack *stack, LsStData data);

LsStData popLsStack(LsStack *stack);

void printLsStNode(LsStNode* node);

void traverseLsStack(LsStack stack);

void freeLsStack(LsStack *stack);

#endif // STACK_LIST_H
