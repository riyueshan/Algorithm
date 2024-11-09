#ifndef TREE_HF_H
#define TREE_HF_H

#include "../data_tree.h"

SqHfTree createHfTree(HfTrData data[], int n);

void printHfData(HfTrData data);

void traverseHfTree(SqHfTrNode *tree, int p);

void saveHfTree(SqHfTree tree, char *filename);

void freeHfTree(SqHfTrNode *tree);


#endif // TREE_HF_H
