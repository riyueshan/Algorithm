#ifndef DATA_H
#define DATA_H

typedef struct Data {
	int id;
	int value;
} LsData;

typedef struct Node {
	LsData data;
	struct Node *next;
} LsNode;

extern LsData NoneLsData;
extern LsData HeadLsData;

#endif // DATA_H
