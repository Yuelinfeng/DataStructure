//
// Created by 25328 on 2023/3/14.
//
#include "crossLinkGraph.h"
#include <iostream>
using namespace std;
static void setupGraph(CrossGraph *graph)
{
    char *nodeName[] = {"V0","V1","v2","V3"};
    int n = sizeof(nodeName)/sizeof(nodeName[0]);
    initCrossVex(graph, n, nodeName);
    addCrossArc(graph, 0, 3, 1);
    addCrossArc(graph, 1, 0, 1);
    addCrossArc(graph, 1, 2, 1);
    addCrossArc(graph, 2, 0, 1);
    addCrossArc(graph, 2, 1, 1);
}
void test01()
{
    int n = 4;
    crossGraph *graph = createCrossGraph(n);
    setupGraph(graph);
    printf("V0的入度为：%d\n", inDegreeCrossGraph(graph, 0));
    printf("V0的出度为：%d\n", outDegreeCrossGraph(graph,0));
    releaseCrossGraph(graph);
}
int main()
{
    test01();
}
