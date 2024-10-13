//
// Created by riyueshan on 10/12/24.
//

#ifndef LIST_NORMAL_H
#define LIST_NORMAL_H

#define HEAD_NODE_ID -1

typedef struct ID {
    int id;
} ID;

typedef struct Data {
    ID Id; // the only identifier of each node
    char val;
} Data;

typedef struct Node {
    Data data;
    struct Node *next;
} Node;

typedef Node *NodePtr;

void initListNormal(NodePtr *list);

void insertNode(NodePtr list, Node node);

void insertNode_Empty(NodePtr *list, Node node);

void insertNodeTail(NodePtr *list, Node node);

void insertNodeTail_Empty(NodePtr *list, Node node);

void deleteNode_Index(NodePtr *list, int index);

void deleteNode_ID(NodePtr *list, ID id);

void modifyList(NodePtr list, int index, Node node_new);

void modifyNode(NodePtr list, int index, Data data_new);

NodePtr searchNode(NodePtr list, int index);

int searchNodeIndex(NodePtr list, ID id);

void clearListNormal(NodePtr *list);

#endif //LIST_NORMAL_H
