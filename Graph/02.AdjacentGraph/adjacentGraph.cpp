//
// Created by 25328 on 2023/3/6.
//

#include "adjacentGraph.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>

AGraph *createAGraph(int n) {
    // 创建结构
    AGraph * graph = new AGraph;
    graph->nodes = new ArcNode[n];
    graph->nodeNum = n;
    // 初始化
    memset(graph->nodes, 0, sizeof(ArcNode) * n);
    return graph;
}

void releaseAGraph(AGraph *graph) {
    int count = 0;
    if (graph)
    {
        ArcEdge *tmp;
        for (int i = 0; i < graph->nodeNum; ++i) { // 获取节点数组
            ArcEdge *edge = graph->nodes[i].firstEdge;
            while (edge)
            {
                tmp = edge;
                edge = edge->next;
                delete tmp;
                count++;
            }
        }
        printf("release %d edges\n", count);
    }
}

void initAGraph(AGraph *graph, int num, char **names, int directed) {
    if (graph)
    {
        graph->directed = directed;
        for (int i = 0; i < num; ++i) {
            graph->nodes[i].no = i;
            graph->nodes[i].show = names[i];
        }
    }
}
// 创造边
static ArcEdge *createArcEdge(int y, int w)
{
    ArcEdge *edge = new ArcEdge;
    edge->no = y;
    edge->weight = w;
    return edge;
}
void addGraphEdge(AGraph *graph, int x, int y, int w) {
    if (x < 0 || x >= graph->nodeNum || y < 0 || y > graph->nodeNum)
        return;
    // 边节点采用头插法
    ArcEdge *edge = createArcEdge(y, w);
    edge->next = graph->nodes[x].firstEdge;
    graph->nodes[x].firstEdge = edge;
    graph->edgeNum++;
    if (x != y && graph->directed == 0) // 不是自环边且是无向图
    {
        edge = createArcEdge(x,w);
        edge->next = graph->nodes[y].firstEdge;
        graph->nodes[y].firstEdge = edge;
        graph->edgeNum++;
    }
}
