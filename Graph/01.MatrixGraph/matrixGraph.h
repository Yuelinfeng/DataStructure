//
// Created by 25328 on 2023/3/8.
//

#ifndef DATASTRUCTURE_MATRIXGRAPH_H
#define DATASTRUCTURE_MATRIXGRAPH_H
#include "../base.h"
/*
 * 邻接矩阵：顶点集和边集
 * */
typedef struct
{
    int no;     // 顶点编号
    char* show; //显示数据
}MatrixVertex;
typedef int MatrixEdge;//用int类型来描述邻接矩阵的边的权值
// 矩阵初始化
typedef struct
{
    MatrixVertex vex[MaxNodeNum];              //顶点集
    MatrixEdge edges[MaxNodeNum][MaxNodeNum];  //边集
    int nodeNum;                               //顶点最大数量
    int edgeNum;                               // 边的最大数量
    bool directed;                              // 是否为有向图
}MGraph;
/*
 * 邻接矩阵初始化：点集初始化、边集初始化
 *      点集初始化：
 *          - 点结构初始化
 *          - 显示的字符串初始化
 *          - 初始化权值的边
 * */
void initMGraph(MGraph *g, int num, char *names[], bool directed, int edgeValue);
void addMGraphEdge(MGraph *g, int x, int y, int w);

#endif //DATASTRUCTURE_MATRIXGRAPH_H
