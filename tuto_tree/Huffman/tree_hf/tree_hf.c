#include <stdio.h>
#include <stdlib.h>
#include "tree_hf.h"

HfTrData NoneHfTrData = {0, '\0'};

int *sort(SqHfTrNode *tree, int n) {
	int *rank = malloc(sizeof(int) * n);
	int *used = malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		if (tree[i].parent != -1) {
			used[i] = 1;
		} else {
			used[i] = 0;
		}
	}

	int k = 0;
	int count = 0;
	while (k < n) {
		if (!used[k]) {
			rank[count] = k;
			count++;
		}
		k++;
	}

	for (int i = 0; i < count; i++) {
		for (int j = i; j < count; j++) {
			if (tree[rank[i]].data_hf.weight > tree[rank[j]].data_hf.weight) {
				int temp = rank[i];
				rank[i] = rank[j];
				rank[j] = temp;
			}
		}
	}

	return rank;
}

SqHfTree createHfTree(HfTrData data[], int n) {
	int size = 2 * n - 1;
	SqHfTrNode *table = malloc(sizeof(SqHfTrNode) * size);

	for (int i = 0; i < n; i++) {
		table[i].data_hf = data[i];
		table[i].parent = -1;
		table[i].lchild = -1;
		table[i].rchild = -1;
	}

	for (int i = n; i < size; i++) {
		table[i].data_hf = NoneHfTrData;
		table[i].parent = -1;
		table[i].lchild = -1;
		table[i].rchild = -1;
	}

	for (int i = n; i < size; i++) {
		int *rank = sort(table, i);
		int lchild = rank[0];
		int rchild = rank[1];
		// printf("i:%d\tl:%d\tr:%d\n", i, lchild, rchild);
		table[lchild].parent = i;
		table[rchild].parent = i;
		table[i].lchild = lchild;
		table[i].rchild = rchild;
		table[i].data_hf.weight = table[lchild].data_hf.weight + table[rchild].data_hf.weight;
		free(rank);
	}

	SqHfTree tree = {table, size - 1, size};
	return tree;
}

void printHfData(HfTrData data) {
	printf("%d\t%c\n", data.weight, data.value);
}

void traverseHfTree(SqHfTrNode *tree, int p) {
	printHfData(tree[p].data_hf);
	if (tree[p].lchild == -1 && tree[p].rchild == -1)
		return;

	traverseHfTree(tree, tree[p].lchild);
	traverseHfTree(tree, tree[p].rchild);
}

void saveHfTree(SqHfTree tree, char *filename) {
	FILE *fp = fopen(filename, "w");
	if (fp == NULL) {
		fprintf(stderr, "wrong file path!!!\n");
		return;
	}

	fprintf(fp, "i\tv\tw\tp\tl\tr\n");
	for (int i = 0; i < tree.size; i++) {
		fprintf(fp, "%d\t%c\t%d\t%d\t%d\t%d\n", i, tree.tree[i].data_hf.value, tree.tree[i].data_hf.weight,
		        tree.tree[i].parent, tree.tree[i].lchild, tree.tree[i].rchild);
	}
}

void freeHfTree(SqHfTrNode *tree) {
	if (tree) {
		free(tree);
	}
}
