#include <stdio.h>
#include "stack_sq.h"

int main(void) {
    SqStack stack;

    int n;
    printf("Enter the capacity of sequential stack\n");
    scanf("%d", &n);
    initSqStack(&stack,n);

    for(int i=0;i<n;i++) {
        pushSqStack(&stack,(SqStData){i+1,'a'+i});
    }

    traverseSqStack(stack);

    printf("Poping...\n");
    SqStData data=popSqStack(&stack);
    printf("popped:\t");
    printSqStData(data);
    printf("current\n");
    traverseSqStack(stack);

    freeSqStack(&stack);
    return 0;
}
