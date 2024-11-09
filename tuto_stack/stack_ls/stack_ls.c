#include <stdio.h>
#include <stdlib.h>

#include "stack_ls.h"

void initLsStack(LsStack *stack) {
	stack->top = NULL;
	stack->size = 0;
}

LsStNode *createLsStNode(LsStData data) {
	LsStNode *node = malloc(sizeof(LsStNode));
	if (!node) {
		fprintf(stderr, "Memory allocation failed!!!\n");
		exit(-1);
	}
	node->data = data;
	node->next = NULL;

	return node;
}

int isLsStEmpty(LsStack stack) {
	return stack.top == NULL;
}

void pushLsStack(LsStack *stack, LsStData data) {
	LsStNode *node = createLsStNode(data);

	stack->size++;
	if (isLsStEmpty(*stack)) {
		stack->top = node;
		return;
	}

	node->next = stack->top;
	stack->top = node;
}

LsStData popLsStack(LsStack *stack) {
	if (stack->top == NULL) {
		fprintf(stderr, "Stack is empty.\n");
		exit(1);
	}

	LsStNode *tmp = stack->top;
	LsStData data = tmp->data;
	stack->top = tmp->next;
	free(tmp);
	stack->size--;
	return data;
}

void printLsStNode(LsStNode *node) {
	printf("%d",node->data.value);
}

void traverseLsStack(LsStack stack) {
	LsStNode* p=stack.top;
	while (p) {
		printLsStNode(p);
		p=p->next;
	}
}

void freeLsStack(LsStack *stack) {
	while (!isLsStEmpty(*stack)) {
		popLsStack(stack);
	}
}
