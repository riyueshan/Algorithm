//
// Created by riyueshan on 10/12/24.
//
#include <stdio.h>
#include <stdlib.h>

#include "list_normal.h"

void initListNormal(NodePtr *list) {
    /*
     * initialize list with a head node
     */
    *list = malloc(sizeof(Node));
    (*list)->next = NULL;
    (*list)->data.Id.id = HEAD_NODE_ID;
}

void insertNode(NodePtr list, const Node node) {
    /*
     * insert for list with a head node
     */
    NodePtr node_new = malloc(sizeof(Node));
    node_new->data = node.data;
    node_new->next = NULL;

    NodePtr p = list;
    while (p->next) {
        /* p or **p->next**
         * to insert the node given,
         * we need to find the former one of it,
         * thus stop until we traverse to the last node,
         * and insert to the next of it, where is originally NULL
         */
        p = p->next;
    }

    p->next = node_new;
}

void insertNode_Empty(NodePtr *list, Node node) {
    /*
     * insert for list without a head node
     * since here may be an empty list,
     * which means the list maybe adjusted,
     * so we pass NodePtr* list
     */
    NodePtr node_new = malloc(sizeof(Node));
    node_new->data = node.data;
    node_new->next = NULL;

    if (*list == NULL) {
        // the first node
        *list = node_new;
        return;
    }

    NodePtr p = *list;
    while (p->next) {
        p = p->next;
    }

    p->next = node_new;
}

void insertNodeTail(NodePtr *list, Node node) {
    /*
     * insert for list with a tail node from tail,
     * since list(head) is modified, so pass NodePtr*
     */
    NodePtr node_new = malloc(sizeof(Node));
    node_new->data = node.data;
    node_new->next = *list;
    *list = node_new;
}

void insertNodeTail_Empty(NodePtr *list, Node node) {
    /*
     * insert for list without a tail node from tail,
     * since list(head) is modified, so pass NodePtr*
     */
    NodePtr node_new = malloc(sizeof(Node));
    node_new->data = node.data;
    if (*list == NULL) {
        // the first node
        node_new->next = NULL;
        *list = node_new;
        return;
    }

    node_new->next = *list;
    *list = node_new;
}

void deleteNode_ID(NodePtr *list, ID Id) {
    const int index = searchNodeIndex(*list, Id);
    if (index == -1) {
        fprintf(stderr, "Node ID %d TO BE DELETED NOT EXISTS!!!\n", Id.id);
        return;
    }
    deleteNode_Index(list, index);
}

void deleteNode_Index(NodePtr *list, int index) {
    if (index == -1) {
        fprintf(stderr, "List[%d] TO BE DELETED NOT EXISTS!!!\n", index);
        return;
    }

    /*NOTE: i<index-1
     * "list[i]" is the node to be deleted,
     * thus p move to "list[i-1]".
     */
    NodePtr p = *list;
    for (int i = 0; i < index - 1; i++, p = p->next) {
    }
    if (p == *list) {
        // delete the first node in the list
        *list = p->next;
        free(p);
        return;
    }

    NodePtr temp = p->next->next;
    // node p->next is the node to be deleted
    free(p->next);
    p->next = temp;
}

void modifyList(NodePtr list, int index, Node node_new) {
    if (index == -1) {
        fprintf(stderr, "List[%d] TO BE MODIFIED NOT EXISTS!!!\n", index);
        return;
    }

    /*
     * list[index] is the node to be modified,
     * thus p move to list[index].
     */
    NodePtr p = list;
    for (int i = 0; i < index; i++, p = p->next) {
    }

    *p = node_new;
}

void modifyNode(NodePtr list, int index, Data data_new) {
    if (index == -1) {
        fprintf(stderr, "List[%d] TO BE MODIFIED NOT EXISTS!!!\n", index);
        return;
    }

    /*
     * list[index] is the node to be modified,
     * thus p move to list[index].
     */
    NodePtr p = list;
    for (int i = 0; i < index; i++, p = p->next) {
    }

    p->data = data_new;
}

NodePtr searchNode(NodePtr list, int index) {
    NodePtr p = list;
    for (int i = 0; i < index; i++, p = p->next) {
        if (!p) {
            fprintf(stderr, "List[%d] NOT EXISTS!!!\n", index);
            return NULL;
        }
    }

    return p;
}

int searchNodeIndex(NodePtr list, ID Id) {
    NodePtr p = list;
    int index = 0;

    while (p) {
        /*NOTE: p or p->next
         * to find the node we search,
         * we need to traverse until the next of last node,
         * which is **NULL**
         */
        if (p->data.Id.id == Id.id) {
            return index;
        }
        p = p->next;
        index++;
    }

    return -1;
}

void clearListNormal(NodePtr *list) {
    NodePtr p = *list, q;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }

    *list = NULL;
}
