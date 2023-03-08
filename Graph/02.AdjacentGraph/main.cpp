//
// Created by 25328 on 2023/3/8.
//
#include <cstdio>
#include "adjacentGraph.h"
static void setupGraph(AGraph *graph)
{
    char *nodeNames[] = {"A","B","C","D","E"};
    int size = sizeof(nodeNames) / sizeof(nodeNames[0]);
    initAGraph(graph, size, nodeNames, 1);
    addGraphEdge(graph,0,4,1);
    addGraphEdge(graph,0,3,1);
    addGraphEdge(graph,0,1,1);
    addGraphEdge(graph,1,4,1);
    addGraphEdge(graph,1,2,1);
    addGraphEdge(graph,2,0,1);
    addGraphEdge(graph,3,4,1);
}
int main()
{
    int n = 5;
    AGraph *graph = createAGraph(n);
    setupGraph(graph);
    printf("边数为 : %d \n",graph->edgeNum);
    releaseAGraph(graph);
    return 0;
}