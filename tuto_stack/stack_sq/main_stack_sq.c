#include <stdio.h>
#include "stack_sq.h"

int main(void) {
    SqStack stack_sq;

    int n;
    printf("Enter the capacity of sequential stack\n");
    scanf("%d", &n);
    stack_sq.capacity = n;
    initSqStack(&stack_sq);

    // TEST: pointer and index
    printf("Stack created at %p\n", &stack_sq);
    printf("Stack base at %p\n", stack_sq.base);
    printf("Stack base[0] at %p\n", &(stack_sq.base[0]));
    printf("element on base[0] before assignment is %d\n", stack_sq.base[0].data);
    Elem elem = {{0}, 1};
    pushSqStack(stack_sq, elem);
    printf("element on base[0] is %d\n", stack_sq.base[0].data);

    return 0;
}
