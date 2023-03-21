//
// Created by 25328 on 2023/3/21.
//

#ifndef DATASTRUCTURE_DIJKSTRASHORTPATH_H
#define DATASTRUCTURE_DIJKSTRASHORTPATH_H
#include "../01.MatrixGraph/matrixGraph.h"
/*
 * 以start为源点，上层空间分配dist数组，记录start为源点到其他节点的最短路径权值
 *  上层空间函数分配path数组，记录每个节点从哪个节点来访问的，相当于这个顶点的父亲
 * */
void DijkstraMGraph(const MGraph *graph, int start, int dist[], int path[]);

void showShortPath(const int path[], int num, int pos);
#endif //DATASTRUCTURE_DIJKSTRASHORTPATH_H
