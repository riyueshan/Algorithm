//
// Created by riyueshan on 10/12/24.
//
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void) {
	LsNode *list;
	// initList(&list);

	for (int i = 0; i < 5; i++) {
		addLsNode(&list, (LsData){i + 1, 'a' + i});
	}
	traverseList(list);

	printf("\nLocate sublist from index 2\n");
	LsNode *b = locateSubList(list, 2);
	printf("\nThe start node\t");
	printLsNode(b);
	printf("\nThe sublist with the same address of origin\n");
	traverseList(b);

	printf("\nDelete b\n");
	deleteLsNode(&list, b);
	traverseList(list);


	printf("\nInsert b\n");
	insertLsNode(&list, NULL, (LsData){2, 'b'});
	traverseList(list);

	printf("\nPop first:\t");
	LsNode *p = createLsNode(popLsNode(&list));
	printLsNode(p);
	traverseList(list);

	printf("\nPush first:\n");
	pushLsNode(&list, p->data);
	traverseList(list);

	printf("\nRemove last:\t");
	p = createLsNode(removeLsNode(&list));
	printLsNode(p);
	traverseList(list);

	printf("\nFree list\n");
	freeList(&list);
	traverseList(list);

	printf("End\n");
	return 0;
}
