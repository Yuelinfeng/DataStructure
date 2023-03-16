//
// Created by 25328 on 2023/3/16.
//

#ifndef DATASTRUCTURE_KRUSKAL_H
#define DATASTRUCTURE_KRUSKAL_H
//..上级目录
#include "../base.h"
#include "../01.MatrixGraph/matrixGraph.h"
/*
 * kruskal算法
 * 从边的角度，求图的最小生成树，更适合求边稀疏的图
 * 算法思路：
 *   1。 将所有的边按照权值进行升序排序，然后从小到大一一判断，判断条件：
 *       a. 不会形成回路，保留为最小生成树的一部分
 *       b. 形成回路，舍去
 *   2.  循环a，直到具有n个顶点的连通图具有n-1条边，则停止
 * */

// 使用邻接矩阵表示了无向图，从邻接矩阵中初始化边集数组
int initEdgeSet(const MGraph *graph, EdgeSet *edges);
// 排序边集数组
void sortEdgeSet(EdgeSet *edges, int num);
// Kruskal算法
int KruskalMGraph(const MGraph *graph, const EdgeSet *edges, int num, EdgeSet *result);

#endif //DATASTRUCTURE_KRUSKAL_H
