#include <stdio.h>

#include "stack_ls/stack_ls.h"
#define N_MAX 100
#define K_MAX N_MAX

LsStack stack;

void permutateNK(const int n, const int k, int arr[], int used[]) {
    if (stack.size == k) {
        traverseLsStack(stack);
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }

        used[i] = 1;
        LsStData data;
        data.value = arr[i];
        data.id = -1;
        pushLsStack(&stack, data);
        permutateNK(n, k, arr, used);

        used[i] = 0;
        popLsStack(&stack);
    }
}

int main(void) {
    int arr[N_MAX];
    int used[N_MAX] = {0};

    int n, k;
    printf("Enter N and K,100>=N>=K>1\n");
    scanf("%d%d",&n,&k);

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    initLsStack(&stack);
    permutateNK(n, k, arr, used);

    return 0;
}
