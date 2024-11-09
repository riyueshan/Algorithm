#ifndef DATA_TREE_H
#define DATA_TREE_H

typedef struct BiTrData {
	int id;
	char value;
} BiTrData;

typedef struct BiTrNode {
	// binary linked list
	BiTrData data_bi;
	struct BiTrNode *left;
	struct BiTrNode *right;
} BiTrNode;

typedef struct HfTrData {
	int weight;
	char value;
} HfTrData;

typedef struct SqHfTrNode {
	HfTrData data_hf;
	int parent, lchild, rchild;
} SqHfTrNode;

typedef struct SqHfTree {
	SqHfTrNode *tree;
	int root;
	int size;
} SqHfTree;

extern HfTrData NoneHfTrData;

#endif // DATA_TREE_H
