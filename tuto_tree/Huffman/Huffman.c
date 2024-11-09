#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Huffman.h"

LsStData LEFT = {0};
LsStData RIGHT = {1};

HfTrData *readHfTrData(int size, char *filename) {
	HfTrData *data = malloc(size * sizeof(HfTrData));
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("File not found\n");
		exit(1);
	}

	for (int i = 0; i < size; i++) {
		fscanf(fp, "%c%d", &data[i].value, &data[i].weight);
		int ch;
		while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
		}
	}

	fclose(fp);
	return data;
}

HfCode *createHfCode(SqHfTrNode *tree, int size) {
	HfCode *code = malloc(size * sizeof(HfCode));

	for (int i = 0; i < size; i++) {
		LsStack *stack = malloc(sizeof(LsStack));
		initLsStack(stack);

		code[i].value = tree[i].data_hf.value;

		int p = i;
		while (tree[p].parent != -1) {
			int parent = tree[p].parent;
			if (tree[parent].lchild == p) {
				pushLsStack(stack, LEFT);
			}
			if (tree[parent].rchild == p) {
				pushLsStack(stack, RIGHT);
			}
			p = parent;
		}

		code[i].code = stack;
		code[i].size = stack->size;
	}

	return code;
}

int *enHfCode(char *s, HfCode *code) {
	int i = 0;
	int *result = malloc(CODE_MAX * sizeof(int));

	int count = 0;
	while (s[i] != '\0') {
		int p = 0;
		if (s[i] != ' ') {
			p = s[i] - 'A' + 1;
		}

		LsStNode *q = code[p].code->top;
		while (q) {
			result[count] = q->data.path;
			count++;
			q = q->next;
		}
		i++;
	}

	result[count] = -1;
	return result;
}

char *deHfCode(char *s, SqHfTree tree) {
	char *result = malloc(strlen(s) * sizeof(char));

	int i = 0;
	int count = 0;
	while (s[i] != '\0') {
		int p = tree.root;
		int j = i;
		while (tree.tree[p].lchild != -1) {
			if (s[j] == '0') {
				p = tree.tree[p].lchild;
			} else if (s[j] == '1') {
				p = tree.tree[p].rchild;
			} else {
				fprintf(stderr, "invalid number!!!\n");
				return NULL;
			}
			j++;
		}

		result[count] = tree.tree[p].data_hf.value;
		i = j;
		count++;
	}

	result[count] = '\0';
	return result;
}

void printHfTable(SqHfTrNode *tree, int size) {
	printf("Huffman Table\n");
	printf("i\tv\tw\tp\tl\tr\n");
	for (int i = 0; i < size; i++) {
		printf("%d\t%c\t%d\t%d\t%d\t%d\n", i, tree[i].data_hf.value, tree[i].data_hf.weight, tree[i].parent,
		       tree[i].lchild, tree[i].rchild);
	}
}

void printHfCode(HfCode *code, int size) {
	for (int i = 0; i < size; i++) {
		printf("%c\t", code[i].value);
		traverseLsStack(*code[i].code);
		printf("\n");
	}
}
