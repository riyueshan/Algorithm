#ifndef STACK_SEQUENTIAL_H
#define STACK_SEQUENTIAL_H

typedef struct ID {
    int id;
} ID;

typedef struct {
    ID Id;
    int data;
} Elem;

typedef Elem *ElemPtr;

typedef struct {
    Elem *base;
    int top;
    int capacity;
    int len;
} SqStack;

void initSqStack(SqStack *stack_sq);

void clearSqStack(SqStack stack_sq);

Elem topSqStack(SqStack stack_sq);

void pushSqStack(SqStack stack_sq, Elem e);

ElemPtr getElem(SqStack stack_sq);

Elem popSqStack(SqStack stack_sq);
#endif // STACK_SEQUENTIAL_H
