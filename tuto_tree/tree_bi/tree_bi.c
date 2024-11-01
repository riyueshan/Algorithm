#include <stdio.h>
#include <stdlib.h>

#include "tree_bi.h"
#include "queue_ls.h"

BiNode *createBiNode(BiData data) {
	BiNode *node = malloc(sizeof(BiNode));
	if (node == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		exit(-1);
	}
	node->data_bi = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

BiNode *createBitree(BiData *data, int n) {
	LsQueue queue;
	initLsQueue(&queue);
	BiNode *root = createBiNode(data[0]);
	BiNode *p = root;

	QuData data_qu = {p};

	int i = 1;
	while (i < n) {
		if (p->left && p->right) {
			p = deQueue(&queue).bi_node;
			continue;
		}

		BiNode *node = createBiNode(data[i]);
		data_qu.bi_node = node;
		enQueue(&queue, createQuNode(data_qu));
		i++;
		if (p->left == NULL) {
			p->left = node;
		} else if (p->right == NULL) {
			p->right = node;
		}
	}

	return root;
}


void traversePreOrder(BiNode *root) {
	if (root) {
		printBiNode(root);
		traversePreOrder(root->left);
		traversePreOrder(root->right);
	}
}

void traverseInOrder(BiNode *root) {
	if (root) {
		traverseInOrder(root->left);
		printBiNode(root);
		traverseInOrder(root->right);
	}
}

void traversePostOrder(BiNode *root) {
	if (root) {
		traversePostOrder(root->left);
		traversePostOrder(root->right);
		printBiNode(root);
	}
}

void traverseLevelOrder(BiNode *root) {
	if (!root)return;
	LsQueue queue;
	initLsQueue(&queue);

	BiNode *p = root;
	QuData data_qu = {p};
	enQueue(&queue, createQuNode(data_qu));

	while (!isQueueEmpty(queue)) {
		p = deQueue(&queue).bi_node;
		printBiNode(p);
		if (p->left) {
			data_qu.bi_node = p->left;
			enQueue(&queue, createQuNode(data_qu));
		}
		if (p->right) {
			data_qu.bi_node = p->right;
			enQueue(&queue, createQuNode(data_qu));
		}
	}

	freeLsQueue(queue);
}

void freeBiTree(BiNode **tree) {
	if (*tree) {
		freeBiTree(&(*tree)->left);
		freeBiTree(&(*tree)->right);
		free(*tree);
	}
}

void printBiNode(BiNode *node) {
	printf("%d\t%c\n", node->data_bi.id, node->data_bi.value);
}
