//
// Created by riyueshan on 11/15/24.
//

#ifndef DATA_GRAPH_H
#define DATA_GRAPH_H

typedef  struct Arc{
  int tail;
  int head;
  double weight;
}Arc;

typedef struct ArcData{
  int head;
  double weight;
}ArcData;

typedef struct VData{
  char value;
}VData;

typedef struct ArcNode {
  ArcData data;
  struct ArcNode *nextarc;
} ArcNode;

typedef struct VNode {
  VData data;
  ArcNode *firstarc;
} VNode;

#endif //DATA_GRAPH_H
