//
// Created by 25328 on 23/3/25.
//
#include <cstdio>
#include "topologicalSort.h"

// 无环
AGraph *setupAGraph1() {
    char *names[] = {"0","1","2","3","4","5","6"};
    int n = sizeof(names) / sizeof(names[0]);
    AGraph *graph = createAGraph(n);
    initAGraph(graph, n, names, 1);
    addGraphEdge(graph,0,1,1);
    addGraphEdge(graph,0,2,1);
    addGraphEdge(graph,0,3,1);
    addGraphEdge(graph,1,2,1);
    addGraphEdge(graph,1,4,1);
    addGraphEdge(graph,2,4,1);
    addGraphEdge(graph,2,5,1);
    addGraphEdge(graph,3,5,1);
    addGraphEdge(graph,4,6,1);
    addGraphEdge(graph,5,4,1);
    addGraphEdge(graph,5,6,1);
    return graph;
}

int main() {
    AGraph *graph1 = setupAGraph1();
    int result = TopologicalSort(graph1);
    printf("\nresult is %d\n", result);
    releaseAGraph(graph1);
    return 0;
}