//
// Created by 25328 on 2023/3/15.
//

#ifndef DATASTRUCTURE_ADJACENCYMULTILIST_H
#define DATASTRUCTURE_ADJACENCYMULTILIST_H
/*
 * 邻接多重表，用于无向图，边的删除操作
 * */
// 邻接多重表的边结构
typedef struct amlEdge
{
    int iVex;
    struct amlEdge *iNext;
    int jVex;
    struct amlEdge *jNext;
    int weight;
}AmlEdge;
// 邻接多重表的顶点结构
typedef struct MultiListVertex
{
    int no;
    char *show;
    struct amlEdge *firstEdge;
}multiListVertex;
// 邻接多重表
typedef struct {
    MultiListVertex *nodes;
    int vertexNum;
    int edgeNum;
}AdjacencyMultiList;

// 创建表
AdjacencyMultiList *createMultiList(int n);
void releaseMultiList(AdjacencyMultiList *graph);
void initMultiList(AdjacencyMultiList *graph, int n, char **names);
int insertMultiListEdge(AdjacencyMultiList *graph, int a, int b, int w);
int deleteMultiListEdge(AdjacencyMultiList *graph, int a, int b);
#endif //DATASTRUCTURE_ADJACENCYMULTILIST_H
