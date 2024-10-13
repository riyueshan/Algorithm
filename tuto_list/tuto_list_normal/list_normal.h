//
// Created by riyueshan on 10/12/24.
//

#ifndef LIST_NORMAL_H
#define LIST_NORMAL_H

#define HEAD_NODE_ID -1

typedef struct Data {
    int id; // the only identifier of each node
} Data;

typedef struct Node {
    Data data;
    struct Node *next;
} Node;

typedef Node *NodePtr;

void initListNormal(NodePtr *list);

void insertNode(NodePtr list, Node node);

void insertNode1(NodePtr *list, Node node);

void deleteNode(NodePtr list, Node node);

int searchNode(NodePtr list, Node node);

void clearListNormal(NodePtr* list);

#endif //LIST_NORMAL_H
