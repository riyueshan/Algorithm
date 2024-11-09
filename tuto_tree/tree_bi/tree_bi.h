#ifndef TREE_BI_H
#define TREE_BI_H

#include "../data_tree.h"

BiTrNode *createBiTrNode(BiTrData data);

BiTrNode *createBitree(BiTrData *data, int n);

void traversePreOrder(BiTrNode *root);

void traverseInOrder(BiTrNode *root);

void traversePostOrder(BiTrNode *root);

void traverseLevelOrder(BiTrNode *root);

void freeBiTree(BiTrNode **tree);

void printBiTrNode(BiTrNode *node);

#endif // TREE_BI_H
