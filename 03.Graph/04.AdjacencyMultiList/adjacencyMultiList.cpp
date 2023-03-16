//
// Created by 25328 on 2023/3/15.
//

#include "adjacencyMultiList.h"

AdjacencyMultiList *createMultiList(int n) {
    AdjacencyMultiList *graph = new AdjacencyMultiList;
    graph->nodes = new MultiListVertex[n];
    graph->vertexNum = n;
    graph->edgeNum = 0;
    return graph;
}

void releaseMultiList(AdjacencyMultiList *graph) {

}

void initMultiList(AdjacencyMultiList *graph, int n, char **names) {
    if (graph)
    {
        for (int i = 0; i < n; ++i) {
            graph->nodes[i].no = i;
            graph->nodes[i].show = names[i];
            graph->nodes[i].firstEdge = nullptr;
        }
    }
}

int insertMultiListEdge(AdjacencyMultiList *graph, int a, int b, int w)
{
    // 产生边
    AmlEdge *edge = new AmlEdge;
    edge->weight = w;
    // 处理a节点的连接关系时，使用头插法
    edge->iVex = a;
    edge->iNext = graph->nodes[a].firstEdge;
    graph->nodes[a].firstEdge = edge;
    // 处理b节点，采用头插法
    edge->jVex = b;
    edge->jNext = graph->nodes[b].firstEdge;
    graph->nodes[b].firstEdge = edge;
    graph->edgeNum++;
    return 0;
}

int deleteMultiListEdge(AdjacencyMultiList *graph, int a, int b) {
    // 找到待删除边节点的前一条边节点
    AmlEdge *aCur, *aPre{};
    // 将
    aCur = graph->nodes[a].firstEdge;
    while (aCur &&
            !((aCur->iVex == a) && (aCur->jVex == b) || (aCur->jVex == a) && (aCur->iVex == b)))
    {
        aPre = aCur;
        if (aCur->iVex == a)
        {
            aCur = aCur->iNext;
        }
        else
        {
             aCur = aCur->jNext;
        }
    }
    if(aCur == nullptr)
        return -1;
    // 找b节点
    amlEdge *bCur, *bPre{};
    bCur = graph->nodes[b].firstEdge;
    while (bCur&&
            !((bCur->iVex == a)&&(bCur->jVex == b) || (bCur->jVex == a)&&(bCur->iVex == a)))
    {
        bPre = bCur;
        if(bCur->iVex == b)
            bCur = bCur->iNext;
        else
            bCur = bCur->jNext;
    }
    if(bCur == nullptr)
        return -1;
    // 删除——————————————————————
    // 处理a相关的节点
    if(aPre == nullptr)
    {
        if(aCur->iVex == a)
            graph->nodes[a].firstEdge = aCur->iNext;
        else
            graph->nodes[a].firstEdge = aCur->jNext;
    }
    else
    {
        if (aPre->iVex == a && aCur->iVex == a) {
            aPre->iNext = aCur->iNext;
        }
        else if(aPre->iVex == a && aCur->jVex == a) {  // 是j找到的下一个
            aPre->iNext = aCur->jNext;
        }
        else if (aPre->jVex == a && aCur->iVex == a) {
            aPre->jNext = aCur->iNext;
        }
        else {
            aPre->jNext = aCur->jNext;
        }
//        if (aCur->iVex == a)
//            aPre->iNext = aCur->iNext;
//        else
//            aPre->jNext = aCur->jNext;
    }
    // 再处理b顶点的关系
    if(bPre == nullptr)
    {
        if(bCur->iVex == b)
            graph->nodes[b].firstEdge = bCur->iNext;
        else
            graph->nodes[b].firstEdge = bCur->jNext;
    }
    else
    {
        if (bPre->iVex == b && bCur->iVex == b) {
            bPre->iNext = bCur->iNext;
        }
        else if(bPre->iVex == b && bCur->jVex == b) {  // 是j找到的下一个
            bPre->iNext = bCur->jNext;
        }
        else if (bPre->jVex == a && bCur->iVex == b) {
            bPre->jNext = bCur->iNext;
        }
        else {
            bPre->jNext = bCur->jNext;
        }
//        if(bPre->iVex == a)
//            bPre->iNext = bCur->iNext;
//        else
//            bPre->jNext = bCur->jNext;
    }
    // 释放cur
    delete aCur;
    graph->edgeNum--;
    return 0;
}
