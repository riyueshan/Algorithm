#ifndef LIST_H
#define LIST_H

#include "data_list.h"

void initList(LsNode **list);

LsNode *createLsNode(LsData data);

void addLsNode(LsNode **list, LsData data);

LsData removeLsNode(LsNode **list);

void pushLsNode(LsNode **list, LsData data);

LsData popLsNode(LsNode **list);

LsNode *locateSubList(LsNode *list, int id);

LsData deleteLsNode(LsNode **list, LsNode *out);

void insertLsNode(LsNode **list, LsNode *prev, LsData data);

void traverseList(LsNode *list);

void printLsNode(LsNode *node);

void freeList(LsNode **list);

#endif //LIST_H
