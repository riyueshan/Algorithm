//
// Created by riyueshan on 11/15/24.
//

#ifndef GRAPH_ADJ_H
#define GRAPH_ADJ_H

#include "../data_graph.h"

#define MAX_VERTEX_NUM 20

typedef struct ALGraph {
	VNode* vexs;
	int vexnum, arcnum;
} ALGraph;

ArcNode* createArcNode(ArcData data);

VNode createVNode(VData data);

int getVex(ALGraph* graph, VData vex);

void addArcNode(ALGraph* graph, Arc arc);

ALGraph* createALGraph(VData vexs[], int vexnum, Arc arcs[], int arcnum);

void DFS(ALGraph* graph, int v, int visited[]);

int DFSearch(ALGraph *graph);

void BFS(ALGraph* graph, int v, int visited[]);

int BFSearch(ALGraph *graph);

ALGraph* miniSpanTree_Prim(ALGraph* graph);

void freeALGraph(ALGraph* graph);

#endif //GRAPH_ADJ_H
