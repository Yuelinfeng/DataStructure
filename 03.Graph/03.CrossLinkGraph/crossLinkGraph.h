//
// Created by 25328 on 2023/3/14.
//

#ifndef DATASTRUCTURE_CROSSLINKGRAPH_H
#define DATASTRUCTURE_CROSSLINKGRAPH_H
/*
 * 十字链表，方便查找图中的入度和出度。
 * */
// 十字链表的边结构
typedef struct arcBox
{
    int tailVertex{};
    struct arcBox *tailNext{};
    int headVertex{};
    struct arcBox *headNext{};
    int weight{};
}ArcBox;

// 十字链表的顶点结构
typedef struct crossVertex
{
    int no{};
    const char *show;   //
    arcBox *firstIn{};  // 入度
    arcBox *firstOut{}; // 出度
}CrossVertex;

// 十字链表的图结构
typedef struct crossGraph
{
    CrossVertex *nodes;
    int numVertex;
    int numEdge;
}CrossGraph;

// 产生n个节点的十字链表
crossGraph *createCrossGraph(int n);
// 释放
void releaseCrossGraph(CrossGraph *graph);
// 顶点初始化
void initCrossVex(CrossGraph *graph, int numVex, char **names);
// 添加边，从tail走向head
void addCrossArc(CrossGraph *graph, int tail, int head, int w);
// 计算no编号节点的入度
int inDegreeCrossGraph(CrossGraph *graph, int no);
// 计算no编号节点的入度
int outDegreeCrossGraph(CrossGraph *graph, int no);
#endif //DATASTRUCTURE_CROSSLINKGRAPH_H
