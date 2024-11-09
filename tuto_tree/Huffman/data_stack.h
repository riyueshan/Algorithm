//
// Created by riyueshan on 10/22/24.
//

#ifndef DATA_H
#define DATA_H

typedef struct LsStData {
    int path;
} LsStData;


typedef struct LsStNode {
    LsStData data;
    struct  LsStNode *next;
} LsStNode;

typedef struct SqStData {
    int id;
    int value;
} SqStData;

extern SqStData NoneSqStData;

#endif //DATA_H
