//
// Created by riyueshan on 11/15/24.
//

#include "graph_adj.h"
#include "queue_ls/queue_ls.h"

#include <stdio.h>
#include <stdlib.h>

ArcNode *createArcNode(ArcData data) {
	ArcNode *node = (ArcNode *) malloc(sizeof(ArcNode));
	if (!node) {
		fprintf(stderr, "memory allocation failed\n");
		return NULL;
	}

	node->data = data;
	node->nextarc = NULL;

	return node;
}

VNode createVNode(VData data) {
	VNode node;
	node.data = data;
	node.firstarc = NULL;

	return node;
}

int getVex(ALGraph *graph, VData vex) {
	if (!graph) {
		fprintf(stderr, "graph is NULL\n");
		return -1;
	}
	for (int i = 0; i < graph->vexnum; i++) {
		if (graph->vexs[i].data.value == vex.value) {
			return i;
		}
	}

	return -1;
}

void addArcNode(ALGraph *graph, Arc arc) {
	int tail = arc.tail;
	int head = arc.head;
	ArcNode *node_head = createArcNode((ArcData){head, arc.weight});
	if (graph->vexs[tail].firstarc == NULL) {
		graph->vexs[tail].firstarc = node_head;
	} else {
		ArcNode *p = graph->vexs[tail].firstarc;
		while (p->nextarc != NULL) {
			p = p->nextarc;
		}
		p->nextarc = node_head;
	}
}

ALGraph *createALGraph(VData vexs[], int vexnum, Arc arcs[], int arcnum) {
	ALGraph *graph = (ALGraph *) malloc(sizeof(ALGraph));
	if (!graph) {
		fprintf(stderr, "memory allocation failed\n");
		return NULL;
	}

	graph->arcnum = arcnum;
	graph->vexnum = vexnum;
	graph->vexs = (VNode *) malloc(vexnum * sizeof(VNode));

	for (int i = 0; i < vexnum; i++) {
		graph->vexs[i] = createVNode(vexs[i]);
	}

	for (int i = 0; i < arcnum; i++) {
		addArcNode(graph, arcs[i]);
	}

	return graph;
}

void DFS(ALGraph *graph, int v, int visited[]) {
	visited[v] = 1;
	printf("%d\t%c\n", v, graph->vexs[v].data.value);
	ArcNode *p = graph->vexs[v].firstarc;

	while (p) {
		if (!visited[p->data.head]) {
			DFS(graph, p->data.head, visited);
		}
		p = p->nextarc;
	}
}

int DFSearch(ALGraph *graph) {
	int *visited = (int *) malloc(graph->vexnum * sizeof(int));
	for (int i = 0; i < graph->vexnum; i++) {
		visited[i] = 0;
	}

	int connected = 0;
	for (int i = 0; i < graph->vexnum; i++) {
		if (!visited[i]) {
			connected++;
			DFS(graph, i, visited);
		}
	}

	return connected;
}

void BFS(ALGraph *graph, int v, int visited[]) {
	LsQueue *queue = (LsQueue *) malloc(sizeof(LsQueue));
	initLsQueue(queue);

	enQueue(queue, createLsQuNode((LsQuData){v}));
	while (!isQueueEmpty(*queue)) {
		int vex = deQueue(queue).vex;
		printf("%c(%d)\n", graph->vexs[vex].data.value, vex);
		visited[vex] = 1;

		ArcNode *p = graph->vexs[vex].firstarc;
		while (p) {
			if (!visited[p->data.head]) {
				enQueue(queue, createLsQuNode((LsQuData){p->data.head}));
				visited[p->data.head] = 1;
			}
			p = p->nextarc;
		}
	}
}

int BFSearch(ALGraph *graph) {
	int *visited = (int *) malloc(graph->vexnum * sizeof(int));
	for (int i = 0; i < graph->vexnum; i++) {
		visited[i] = 0;
	}

	int connected = 0;
	for (int i = 0; i < graph->vexnum; i++) {
		if (!visited[i]) {
			connected++;
			BFS(graph, i, visited);
			printf("\n");
		}
	}

	free(visited);

	return connected;
}

int miniPath(Arc *arcs, int size) {
	int min = 0;
	for (int i = 0; i < size; i++) {
		if (arcs[i].weight < arcs[min].weight) {
			min = i;
		}
	}

	return min;
}

void spanTree_Prim(ALGraph *mini_tree, ALGraph *graph, int visited[]) {
	if (mini_tree->vexnum == graph->vexnum) {
		return;
	}

	Arc *arcs = (Arc *) malloc(graph->arcnum * sizeof(Arc));

	int counter = 0;
	for (int i = 0; i < graph->vexnum; i++) {
		if (visited[i]) {
			ArcNode *p = graph->vexs[i].firstarc;
			while (p) {
				if (!visited[p->data.head]) {
					arcs[counter].tail = i;
					arcs[counter].head = p->data.head;
					arcs[counter].weight = p->data.weight;
					counter++;
				}
				p = p->nextarc;
			}
		}
	}

	// for(int i=0;i<counter;i++) {
	// 	printf("%d %lf %d\n", arcs[i].tail, arcs[i].weight, arcs[i].head);
	// }

	int min_arc = miniPath(arcs, counter);
	printf("arc %c-->%c\n", graph->vexs[arcs[min_arc].tail].data.value, graph->vexs[arcs[min_arc].head].data.value);
	addArcNode(mini_tree, arcs[min_arc]);

	int min_head = arcs[min_arc].head;
	mini_tree->vexs[min_head].data = graph->vexs[min_head].data;
	mini_tree->vexs[min_head].firstarc = NULL;
	Arc path;
	path.weight = arcs[min_arc].weight;
	path.head = arcs[min_arc].tail;
	path.tail = arcs[min_arc].head;
	addArcNode(mini_tree, path);
	visited[min_head] = 1;

	mini_tree->vexnum++;
	mini_tree->arcnum++;

	// for(int i=0;i<graph->vexnum;i++) {
	// 	printf("%d ", visited[i]);
	// }
	// printf("\n");
	spanTree_Prim(mini_tree, graph, visited);

	free(arcs);
}

ALGraph *miniSpanTree_Prim(ALGraph *graph) {
	ALGraph *mini_tree = (ALGraph *) malloc(sizeof(ALGraph));
	mini_tree->vexnum = 1;
	mini_tree->arcnum = 1;
	mini_tree->vexs = (VNode *) malloc(graph->vexnum * sizeof(VNode));

	int *visited = (int *) malloc(graph->vexnum * sizeof(int));
	mini_tree->vexs[0].data = graph->vexs[0].data;
	mini_tree->vexs[0].firstarc = NULL;
	visited[0] = 1;
	for (int i = 1; i < graph->vexnum; i++) {
		visited[i] = 0;
	}

	spanTree_Prim(mini_tree, graph, visited);
	free(visited);

	return mini_tree;
}

void freeALGraph(ALGraph *graph) {
	if (!graph->vexs) {
		free(graph->vexs);
	}

	graph->arcnum = 0;
	graph->vexnum = 0;
}
