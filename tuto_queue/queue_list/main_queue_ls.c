#include <stdio.h>
#include "queue_ls.h"

int main(void) {
	LsQueue queue;
	initLsQueue(&queue);

	for (int i = 0; i < 5; i++) {
		enLsQueue(&queue, (LsQuData){i + 1, 'a' + i});
	}

	traverseLsQueue(queue);

	LsQuData data = deLsQueue(&queue);
	printf("Pop: %d\t%c\n", data.id, data.value);

	printf("Push 6\n");
	enLsQueue(&queue, (LsQuData){6, 'f'});
	traverseLsQueue(queue);

	freeLsQueue(&queue);

	return 0;
}
