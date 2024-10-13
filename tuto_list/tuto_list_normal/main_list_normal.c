//
// Created by riyueshan on 10/12/24.
//
#include <stdio.h>
#include <stdlib.h>

#include "list_normal.h"

void printList(NodePtr list) {
    NodePtr p = list;
    while (p) {
        printf("%d", p->data.id);
        p = p->next;
    }

    printf("\n");
}

int main(void) {
    NodePtr list = NULL;

    initListNormal(&list);
    int n = 10;

    for (int i = 0; i < n; i++) {
        Node node;
        node.data.id = i;
        node.next = NULL;
        insertNode(list, node);
    }
    printf("List before delete\n");
    printList(list);

    Node out = {2,NULL};
    deleteNode(list, out);
    printf("List after delete\n");
    printList(list);

    clearListNormal(&list);
    printList(list);
    printf("List is cleared\n");
    return 0;
}
