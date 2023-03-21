//
// Created by 25328 on 2023/3/16.
//

#include "Kruskal.h"
#include <cstring>

/*
 * 初始化边集数组，只用遍历上三角
 *
 * */
int initEdgeSet(const MGraph *graph, EdgeSet *edges) {
    int k = 0;
    for (int i = 0; i < graph->nodeNum; ++i) {          // 遍历每个节点
        for (int j = i + 1; j < graph->nodeNum; ++j) {  // 遍历每个节点，所有的边，i+1，遍历上三角
            if(graph->edges[i][j] > 0) {
                edges[k].begin = i;
                edges[k].end = j;
                edges[k].weight = graph->edges[i][j];
                k++;
            }
        }
    }
    return k;
}
/* 按照边的权值从小到大进行排序
 * 冒泡方法，第i个元素和后面元素比较，如果后面的权值小，交换
 * 通过一次遍历，当前的i就是最小值
 * */
void sortEdgeSet(EdgeSet *edges, int num) {
    EdgeSet tmp;
    for (int i = 0; i < num; ++i) {
        for (int j = i + 1; j < num; ++j) {
            if (edges[j].weight < edges[i].weight) {
                memcpy(&tmp, &edges[i], sizeof(EdgeSet));
                memcpy(&edges[i],&edges[j], sizeof(EdgeSet));
                memcpy(&edges[j],&tmp,sizeof(EdgeSet));
            }
        }
    }
}
// 从并查集中，找a节点的根节点
static int getRoot(const int* uSet, int a) {
    while (a != uSet[a])
        a = uSet[a];
    return a;
}
int KruskalMGraph(const MGraph *graph, const EdgeSet *edges, int num, EdgeSet *result) {
// 1. 初始化并查集, 每一个节点的编号就是自己
    int *uSet;
    int a, b;
    int count = 0;  //数量
    int sum = 0;    // 权值总和
    uSet = new int[graph->nodeNum]; //初始化一个节点数量的查并集
    //每一个节点的编号就是自己
    for (int i = 0; i < graph->nodeNum; ++i) {
        uSet[i] = i;
    }
// 2. 从已经排序好的边集中，找到最小的边（顺序找），当这个边加入后，不构成闭环，就加入结果
    // 优化：
    for (int i = 0; (count < (graph->nodeNum - 1)) && i < num; ++i) {
        a = getRoot(uSet, edges[i].begin);
        b = getRoot(uSet, edges[i].end);
        if(a != b) {    // 不构成环
            uSet[a] = b;
            result[count].begin = edges[i].begin;
            result[count].end = edges[i].end;
            result[count].weight = edges[i].weight;
            count++;
            sum += edges[i].weight;
        }
    }
    delete[] uSet;
    return sum;
}
