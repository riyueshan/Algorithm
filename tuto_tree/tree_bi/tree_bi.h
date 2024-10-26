#ifndef TREE_BI_H
#define TREE_BI_H

#include "data.h"

typedef struct BiNode {
    // trinary linked list
    Data data;
    struct BiNode *parent;
    struct BiNode *left;
    struct BiNode *right;
} BiNode;

typedef BiNode* BiNodePtr;

void initBiTree(BiNodePtr *root);

BiNodePtr getParent(BiNodePtr root, Data data);

void insertBiNode_Left(BiNodePtr *root, Data data);

void insertBiNode_Right(BiNodePtr *root, Data data);

void traverseBiTree_LDR(BiNodePtr root);

void traverseBiTree_DLR(BiNodePtr root);

void traverseBiTree_LRD(BiNodePtr root);

void traverseBiTree_LR(BiNodePtr root);

#endif // TREE_BI_H