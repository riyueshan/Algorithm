#ifndef HUFFMAN_H
#define HUFFMAN_H

#define CODE_MAX 10*256

#include "tree_hf/tree_hf.h"
#include "stack_ls/stack_ls.h"

typedef struct HfCode {
	LsStack *code;
	char value;
	int size;
} HfCode;

HfTrData *readHfTrData(int size, char *filename);

HfCode *createHfCode(SqHfTrNode *tree, int size);

int *enHfCode(char *s, HfCode *code);

char *deHfCode(char *s, SqHfTree tree);

void printHfTable(SqHfTrNode *tree, int size);

void printHfCode(HfCode *code, int size);

#endif //HUFFMAN_H
