//
// Created by riyueshan on 10/22/24.
//

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

typedef struct LsQuData {
	BiTrNode *bi_node;
} LsQuData;

typedef struct LsQuNode {
	LsQuData data_qu;
	struct LsQuNode *next;
} LsQuNode;

#endif // DATA_TREE_H
