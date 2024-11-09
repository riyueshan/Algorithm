//
// Created by riyueshan on 10/22/24.
//

#ifndef DATA_H
#define DATA_H

typedef struct Data {
    int id;
    int value;
} LsQuData;

typedef struct QuNode {
    LsQuData data;
    struct QuNode *next;
} LsQuNode;

typedef struct LsQueue{
    LsQuNode *front;
    LsQuNode *rear;
    int size;
} LsQueue;

extern LsQuData NoneLsQuData;

#endif //DATA_H
