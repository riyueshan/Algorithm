//
// Created by riyueshan on 10/22/24.
//

#ifndef DATA_H
#define DATA_H

typedef struct BiData {
	int id;
	char value;
} BiData;

typedef struct BiNode {
	// binary linked list
	BiData data_bi;
	struct BiNode *left;
	struct BiNode *right;
} BiNode;

typedef struct QuData {
	BiNode *bi_node;
} QuData;

typedef struct QuNode {
	QuData data_qu;
	struct QuNode *next;
} QuNode;

#endif // DATA_H
