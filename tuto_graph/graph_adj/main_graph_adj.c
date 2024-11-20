//
// Created by riyueshan on 11/15/24.
//

#include <stdlib.h>
#include <stdio.h>

#include "graph_adj.h"

void printALGraph(ALGraph* graph) {
	if(!graph) {
		fprintf(stderr, "graph is NULL\n");
		return;
	}
	for(int i=0;i<graph->vexnum;i++) {
		printf("%c", graph->vexs[i].data.value);
		ArcNode* p = graph->vexs[i].firstarc;
		while(p) {
			printf(" %lf %c",p->data.weight,graph->vexs[p->data.head].data.value);
			p = p->nextarc;
		}
		printf("\n");
	}
}

void nextLine(FILE *fp) {
	char c;
	while((c=fgetc(fp))!='\n' && c!=EOF);
}

int main(void) {
	FILE *fp = fopen("/home/riyueshan/T/Tuto/Algorithm/algorithm/tuto_graph/graph_adj/data.txt", "r");
	if(!fp) {
		fprintf(stderr, "file open failed\n");
		return -1;
	}

	int vexnum, arcnum;
	fscanf(fp, "%d%d", &vexnum, &arcnum);
	nextLine(fp);
	VData* vexs = (VData*)malloc(vexnum*sizeof(VData));
	for(int i=0;i<vexnum;i++) {
		char value;
		fscanf(fp, "%c", &value);
		if(value>='A' && value<='Z') {
			vexs[i].value = value;
		} else {
			i--;
			continue;
		}
		// printf("%c\n", vexs[i].value);
	}
	// NOTE: Undigraph
	arcnum=arcnum*2;
	Arc* arcs = (Arc*)malloc(arcnum*sizeof(Arc));
	for(int i=0;i<arcnum;i++) {
		fscanf(fp, "%d%lf%d", &arcs[i].tail, &arcs[i].weight,&arcs[i].head);
		// printf("%d %lf %d\n", arcs[i].tail, arcs[i].weight, arcs[i].head);
		nextLine(fp);
	}

	fclose(fp);
	ALGraph* graph = createALGraph(vexs, vexnum, arcs, arcnum);
	// printALGraph(graph);

	// printf("Depth First Search:\n");
	int connected=DFSearch(graph);
	printf("connected = %d\n", connected);
	//
	// printf("Broad First Search:\n");
	// BFSearch(graph);

	ALGraph*mini_tree=miniSpanTree_Prim(graph);
	printALGraph(mini_tree);

	DFSearch(mini_tree);

	freeALGraph(graph);
	return 0;

}