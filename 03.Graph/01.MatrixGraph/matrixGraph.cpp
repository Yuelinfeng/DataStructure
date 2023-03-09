//
// Created by 25328 on 2023/3/8.
//

#include "matrixGraph.h"
#include <cstring>
#include <iostream>
void initMGraph(MGraph *g, int num, char **names, bool directed, int edgeValue) {
    g->directed = directed;
    g->edgeNum = 0;            // 边集开始没有，为0
    g->nodeNum = num;
    memset(g->vex, 0, sizeof (g->vex));
    memset(g->edges, 0, sizeof (MatrixEdge) * MaxNodeNum * MaxNodeNum);
    // 初始化顶点
    for (int i = 0; i < num; ++i) {
        g->vex[i].no = i;
        g->vex[i].show = names[i];
        for (int j = 0; j < num; ++j) {
            g->edges[i][j] = edgeValue;
        }
    }
}

/*
 *  添加边的逻辑：
 *     - 首先要添加的位置要正确
 *     - 简单图，不能有自环，重边
 *     - 判断是否边已经存在
 *     - 添加
 * */
static bool isEdge(int w)
{
    if (w > 0 && w < INF)
        return true;
    return false;
}

void addMGraphEdge(MGraph *g, int x, int y, int w) {
    if (x < 0 || x > g->nodeNum)
        return;
    if (y < 0 || y > g->nodeNum)
        return;
    if (!isEdge(g->edges[x][y]))
    {
        // 有向图
        g->edges[x][y] = w;
        // 无向图
        if (g->directed == 0) {
            g->edges[y][x] = w;
        }
        g->edgeNum++;
    }
}

static void visitNode(MatrixVertex *node)
{
    if (node)
    {
        printf("\t%s,",node->show);
    }
}
// 记录是否访问的标记
static int MGraphVisited[MaxNodeNum];
// 递归
void DFSMGraphTravel(MGraph *graph, int v) {
    visitNode(&graph->vex[v]);
    MGraphVisited[v] = 1;
    // 从v号节点开始，递归，深度遍历
    for (int i = 0; i < graph->nodeNum; ++i) {
        if (isEdge(graph->edges[v][i]) && MGraphVisited[i] == 0)
        {
            DFSMGraphTravel(graph,i);
        }
    }
}
void clearMGraphVisit()
{
    memset(MGraphVisited,0,sizeof(MGraphVisited));
}

void BFSMGraphTravel(MGraph *graph, int v) {
    int que[MaxNodeNum]; // 定义队列
    int rear = 0, front = 0;
    int cur;

    rear = (rear + 1) % MaxNodeNum;
    que[rear] = v;
    while (rear != front)
    {
        // 出队
        front = (front + 1) % MaxNodeNum;
        cur = que[front];
        // 设置已经访问
        MGraphVisited[cur] = 1;
        visitNode(&graph->vex[cur]);
        for (int i = 0; i < graph->nodeNum; ++i) {
            if (isEdge(graph->edges[cur][i]) && MGraphVisited[i] == 0)
            {
                // 入队
                rear = (rear +1) % MaxNodeNum;
                que[rear] = i;
                MGraphVisited[i] = 1;
            }
        }
    }
}
