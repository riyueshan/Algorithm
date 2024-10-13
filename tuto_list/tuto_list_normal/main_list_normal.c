//
// Created by riyueshan on 10/12/24.
//
#include <stdio.h>
#include <stdlib.h>

#include "list_normal.h"

void printList(NodePtr list) {
    NodePtr p = list;
    while (p) {
        printf("%d\t", p->data.Id.id);
        printf(" %c\n", p->data.val);
        p = p->next;
    }

    printf("\n");
}

int main(void) {
    NodePtr list = NULL;

    // initListNormal(&list);
    int n = 10;

    char val = 'A';
    for (int i = 0; i < n; i++) {
        Node node;
        node.data.Id.id = i;
        node.data.val = val++; // increment after assignment
        node.next = NULL;

        insertNodeTail_Empty(&list, node);
        // insertNodeTail(&list,node);

        // insertNode_Empty(&list, node);
        // insertNode(list,node);
    }
    printf("List before delete\n");
    printList(list);

    deleteNode_Index(&list, 0);
    printf("List after delete list[0]\n");
    printList(list);

    const ID out = {0};
    deleteNode_ID(&list, out);
    printf("List after delete Id 0\n");
    printList(list);

    Data data_new = {{0}, 'Z'};
    modifyNode(list, 1, data_new);
    printf("List after modify list[1]\n");
    printList(list);

    if (searchNode(list, 1) != NULL) {
        printf("Node list[1] exists\n");
    } else {
        printf("Node list[1] does not exist\n");
    }

    if (searchNodeIndex(list, out) != -1) {
        printf("Node Id 0 exists\n");
    } else {
        printf("Node Id 0 does not exist\n");
    }

    clearListNormal(&list);
    printList(list);
    printf("List is cleared\n");
    return 0;
}
