//
// Created by 25328 on 2023/3/8.
//
#include <cstdio>
#include "matrixGraph.h"
static void setupMatrixGrah(MGraph *g1)
{
    // 双引号天然就是地址
    char *nodeNames[] = {"V1","V2","v3","v4","v5","v6","v7","v8"};
    //
    initMGraph(g1, 8, nodeNames, false, INF);
    addMGraphEdge(g1,0,1,1);
    addMGraphEdge(g1,0,2,1);
    addMGraphEdge(g1,1,3,1);
    addMGraphEdge(g1,1,4,1);
    addMGraphEdge(g1,2,5,1);
    addMGraphEdge(g1,2,6,1);
    addMGraphEdge(g1,3,7,1);
    addMGraphEdge(g1,4,7,1);
    addMGraphEdge(g1,5,6,1);
}
int main()
{
    MGraph g1;
    setupMatrixGrah(&g1);
    printf("has %d num!\n",g1.edgeNum);
    return 0;
}