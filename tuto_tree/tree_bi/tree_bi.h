#ifndef TREE_BI_H
#define TREE_BI_H

#include "data_tree.h"


BiNode *createBiNode(BiData data);

BiNode *createBitree(BiData *data, int n);

void traversePreOrder(BiNode *root);

void traverseInOrder(BiNode *root);

void traversePostOrder(BiNode *root);

void traverseLevelOrder(BiNode *root);

void freeBiTree(BiNode **tree);

void printBiNode(BiNode *node);

#endif // TREE_BI_H
