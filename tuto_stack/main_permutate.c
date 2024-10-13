#include <stdio.h>

#include "stack_list/stack_list.h"
#define N_MAX 100
#define K_MAX N_MAX

Stack stack;

void printStack(const Stack *stack) {
    NodePtr p = getNode(stack);
    while (p) {
        printf("%d ", p->data.value);
        p = p->next;
    }
    printf("\n");
}


void permutateNK(const int n, const int k, int arr[], int used[]) {
    if (stack.len == k) {
        printStack(&stack);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }

        used[i] = 1;
        Data data;
        data.value = arr[i];
        data.Id.id = -1;
        pushStack(&stack, data);
        permutateNK(n, k, arr, used);

        used[i] = 0;
        popStack(&stack);
    }
}

int main(void) {
    int arr[N_MAX];
    int used[N_MAX] = {0};

    int n, k;
    printf("Enter N and K,100>=N>=K>1\n");
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    initStack(&stack);
    permutateNK(n, k, arr, used);

    return 0;
}
