//
// Created by 25328 on 2023/3/21.
//

#include "Prim.h"

int PrimMGraph(MGraph *graph, int startV, EdgeSet *result) {
    int *cost;      // 图中各顶点的权值数组
    int *mark;      // 图中的顶点激活状态
    int *visit;     // 定义从哪个顶点访问到这个顶点
    int sum = 0;
    int min, k;

    cost = new int[graph->nodeNum];
    mark = new int[graph->nodeNum];
    visit = new int[graph->nodeNum];

    // 1. 激活的第一个顶点，就是初始化，先初始化cost路径代价
    for (int i = 0; i < graph->nodeNum; ++i) {
        cost[i] = graph->edges[startV][i];
        mark[i] = 0;
        if(cost[i] < INF) {
            visit[i] = startV;
        }else{
            visit[i] = -1;
        }
    }
    mark[startV] = 1;

    // 2. 激活节点，添加到边集
    for (int i = 0; i < graph->nodeNum - 1; ++i) { //查找n-1最小生成树的边
        min = INF;
        // 从权值代价数组里，找到未激活节点的最小值
        for (int j = 0; j < graph->nodeNum; ++j) { // 从cost
            if (mark[j] == 0 && cost[j] < min) {
                min = cost[j];
                k = j;
            }
        }
        mark[k] = 1;
        result[i].begin = visit[k];
        result[i].end = k;
        result[i].weight = min;
        sum += min;

        // 3.每激活一个顶点后，要更新cost和访问记录
        for (int j = 0; j < graph->nodeNum; ++j) {
            if (mark[j] == 0 && graph->edges[k][j] < cost[j]) {
                cost[j] = graph->edges[k][j];
                visit[j] = k;
            }
        }
    }
    delete[] cost;
    delete[] mark;
    delete[] visit;
    return sum;
}
