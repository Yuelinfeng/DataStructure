//
// Created by 25328 on 2023/3/21.
//

#include "DijkstraShortPath.h"
#include <stack>
#include <cstdio>

/* 算法概述：
 *     1. 初始化dist和path
 *     2. 激活start编号到各节点的权值到dist数组里
 *          2.1 更新path信息
 *     3. 寻找未激活节点中，dist距离最小的节点，将其激活
 *          3.1 更新dist信息（节点激活后，有没有更小的距离）
 *          3.2 同时将激活节点对应path设置为前一个节点信息
 * */
void DijkstraMGraph(const MGraph *graph, int start, int *dist, int *path) {
    int *mark = new int[graph->nodeNum];     // 节点访问记录
    // 1.激活start后，更新dist 和 path
    for (int i = 0; i < graph->nodeNum; ++i) {
        dist[i] = graph->edges[start][i];
        mark[i] = 0;
        if (dist[i] < INF)
            path[i] = start;
        else
            path[i] = -1;
    }
    mark[start] = 1;
    dist[start] = 0;

    // 2. 每次从dist中查找未激活顶点的最小值
    int min;
    int tmpIndex;
    for (int i = 0; i < graph->nodeNum - 1; ++i) {
        min = INF;
        // 从未激活的节点中，找到一个源点的最短距离
        for (int j = 0; j < graph->nodeNum; ++j) {
            if (mark[j] == 0 && dist[j] < min) {
                min = dist[j];
                tmpIndex = j;
            }
        }
        mark[tmpIndex] = 1;
        // 以刚刚激活的节点，更新到其他节点的距离
        for (int j = 0; j < graph->nodeNum; ++j) {
            if (mark[j] == 0 && dist[tmpIndex] + graph->edges[tmpIndex][j] < dist[j])
            {
                dist[j] = dist[tmpIndex] + graph->edges[tmpIndex][j];
                path[j] = tmpIndex;
            }
        }
    }
    delete[] mark;
}

// 定义栈来倒着打印
// pos编号的顶点找上一个顶点，每找到就压栈，最后弹出
void showShortPath(const int *path, int pos) {
    std::stack<int> stack;
    // 不断把父节点压栈，直到发现-1
    while (path[pos] != -1)
    {
        stack.push(pos);
        pos = path[pos];
    }
    stack.push(pos);
    // 2. 弹出打印
    while (!stack.empty()) {
        printf("\t%d",stack.top());
        stack.pop();
    }
    printf("\n");
}
