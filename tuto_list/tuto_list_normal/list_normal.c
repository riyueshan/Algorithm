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
    (*list)->data.id = HEAD_NODE_ID;
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

void insertNode1(NodePtr *list, Node node) {
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

void deleteNode(NodePtr list, Node node) {
    NodePtr p = list;
    const int index = searchNode(list, node);
    if (index == -1) {
        return;
    }

    /*NOTE: i<index-1
     * "list[i]" is the node to be deleted,
     * thus p move to "list[i-1]".
     */
    for (int i = 0; i < index - 1; i++, p = p->next) {
    }

    if (p == list) {
        // delete the first node in the list
        list->next = p->next;
        free(p);
        return;
    }

    NodePtr temp = p->next->next;
    // node p->next is the node to be deleted
    free(p->next);
    p->next = temp;
}

int searchNode(NodePtr list, Node node) {
    NodePtr p = list;
    int index = 0;

    while (p) {
        /*NOTE: p or p->next
         * to find the node we search,
         * we need to traverse until the next of last node,
         * which is **NULL**
         */
        if (p->data.id == node.data.id) {
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
