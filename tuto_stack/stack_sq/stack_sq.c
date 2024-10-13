#include <stdio.h>
#include <stdlib.h>
#include "stack_sq.h"

void initSqStack(SqStack *stack_sq) {
    // NOTE: pointer as param
    // s which point to this stack, stay unchanged, so we don't need to return it

    // NOTE: malloc() and assignment
    // malloc() returns a **void pointer**, which must typecast to the desired type before assignment
    if (!stack_sq->capacity) {
        fprintf(stderr, "WRONG CAPACITY OF SQ_STACK!!!\n");
        return;
    }

    stack_sq->base = (Elem *) malloc(stack_sq->capacity * sizeof(Elem));
    if (stack_sq->base == NULL) {
        fprintf(stderr, "ERROR MALLOC!!!\n");
        return;
    }

    // NOTE: index of allocated pointer
    // by default, base start from index base[0],
    // so top = -1 means the stack is empty, and ++top will point to base[0]
    stack_sq->top = -1;
    stack_sq->len = 0;
};

void clearSqStack(SqStack stack_sq) {
    // NOTE: free() and NULL
    // free() is used to deallocate memory previously allocated by malloc(), alloc(), or realloc()
    // NULL is to ensure the stack is empty to avoid dangling pointer
    free(stack_sq.base);
    stack_sq.base = NULL;
    stack_sq.capacity = 0;
    stack_sq.top = -1;
    stack_sq.len = 0;
};

Elem topSqStack(SqStack stack) {
    if (stack.top == -1) {
        fprintf(stderr, "GET TOP FROM EMPTY SQ_STACK!!!\n");
        return (Elem){0};
    }

    return stack.base[stack.top];
};

void pushSqStack(SqStack stack_sq, Elem e) {
    if (stack_sq.top == stack_sq.capacity - 1) {
        return;
    }

    stack_sq.base[++stack_sq.top] = e;
    stack_sq.len++;
}

ElemPtr getElem(SqStack stack_sq) {
    return stack_sq.base;
};

Elem popSqStack(SqStack stack_sq) {
    if (stack_sq.top == -1) {
        if (stack_sq.top == -1) {
            fprintf(stderr, "POP TOP FROM EMPTY SQ_STACK!!!\n");
            return (Elem){0};
        }
    }

    stack_sq.len--;
    return stack_sq.base[stack_sq.top--];
};
