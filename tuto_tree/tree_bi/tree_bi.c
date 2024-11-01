#include <stdio.h>
#include <stdlib.h>

#include "tree_bi.h"
#include "queue_ls.h"

BiTrNode *createBiTrNode(BiTrData data) {
	BiTrNode *node = malloc(sizeof(BiTrNode));
	if (node == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		exit(-1);
	}
	node->data_bi = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

BiTrNode *createBitree(BiTrData *data, int n) {
	LsQueue queue;
	initLsQueue(&queue);
	BiTrNode *root = createBiTrNode(data[0]);
	BiTrNode *p = root;

	int i = 1;
	while (i < n) {
		if (p->left && p->right) {
			p = deQueue(&queue).bi_node;
			continue;
		}

		BiTrNode *node = createBiTrNode(data[i]);
		enQueue(&queue, createLsQuNode((LsQuData){node}));
		i++;
		if (p->left == NULL) {
			p->left = node;
		} else if (p->right == NULL) {
			p->right = node;
		}
	}

	return root;
}

void traversePreOrder(BiTrNode *root) {
	if (root) {
		printBiTrNode(root);
		traversePreOrder(root->left);
		traversePreOrder(root->right);
	}
}

void traverseInOrder(BiTrNode *root) {
	if (root) {
		traverseInOrder(root->left);
		printBiTrNode(root);
		traverseInOrder(root->right);
	}
}

void traversePostOrder(BiTrNode *root) {
	if (root) {
		traversePostOrder(root->left);
		traversePostOrder(root->right);
		printBiTrNode(root);
	}
}

void traverseLevelOrder(BiTrNode *root) {
	if (!root)
		return;
	LsQueue queue;
	initLsQueue(&queue);

	BiTrNode *p = root;
	enQueue(&queue, createLsQuNode((LsQuData){p}));

	while (!isQueueEmpty(queue)) {
		p = deQueue(&queue).bi_node;
		printBiTrNode(p);
		if (p->left) {
			enQueue(&queue, createLsQuNode((LsQuData){p->left}));
		}
		if (p->right) {
			enQueue(&queue, createLsQuNode((LsQuData){p->right}));
		}
	}

	freeLsQueue(queue);
}

void freeBiTree(BiTrNode **tree) {
	if (*tree) {
		freeBiTree(&(*tree)->left);
		freeBiTree(&(*tree)->right);
		free(*tree);
	}
}

void printBiTrNode(BiTrNode *node) {
	printf("%d\t%c\n", node->data_bi.id, node->data_bi.value);
}
