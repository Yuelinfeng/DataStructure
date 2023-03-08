//
// Created by 25328 on 2023/3/8.
//

#include "matrixGraph.h"
#include <string.h>
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
static bool hasEdge(int w)
{
    if (w < 0 || w > INF)
        return 1;
    return 0;
}
void addMGraphEdge(MGraph *g, int x, int y, int w) {
    if (x < 0 || x > g->nodeNum)
        return;
    if (y < 0 || y > g->nodeNum)
        return;
    if (!hasEdge(g->edges[x][y]))
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
