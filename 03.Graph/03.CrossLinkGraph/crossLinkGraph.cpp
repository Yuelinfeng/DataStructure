//
// Created by 25328 on 2023/3/14.
//

#include "crossLinkGraph.h"

crossGraph *createCrossGraph(int n) {
    CrossGraph *graph = new CrossGraph;
    graph->nodes = new CrossVertex[n];
    graph->numVertex = n;
    graph->numEdge = 0;
    return graph;
}

void releaseCrossGraph(CrossGraph *graph) {
    if (graph)
    {
        if (graph->nodes)
        {
            delete[] graph->nodes;
        }
        delete graph;
    }
}

void initCrossVex(CrossGraph *graph, int numVex, char **names) {
    for (int i = 0; i < numVex; ++i) {
        graph->nodes[i].no = i;
        graph->nodes[i].show = names[i];
        graph->nodes[i].firstIn = graph->nodes[i].firstOut = nullptr;
    }
}

void addCrossArc(CrossGraph *graph, int tail, int head, int w) {
    ArcBox *edge = new ArcBox;
    edge->weight = w;
    // 使用头插法，出度
    edge->tailVertex = tail;
    edge->tailNext = graph->nodes[tail].firstOut;
    graph->nodes[tail].firstOut = edge ;
    // 使用头插法，入度
    edge->headVertex = head;
    edge->headNext = graph->nodes[head].firstIn;
    graph->nodes[head].firstIn = edge;
}

int inDegreeCrossGraph(CrossGraph *graph, int no)
{
    int count= 0;
    if (graph)
    {
        ArcBox *box = graph->nodes[no].firstIn;
        while (box)
        {
            count++;
            box = box->headNext;
        }
    }
    return count;
}

int outDegreeCrossGraph(CrossGraph *graph, int no) {
    int count= 0;
    if (graph)
    {
        ArcBox *box = graph->nodes[no].firstOut;
        while (box)
        {
            count++;
            box = box->tailNext;
        }
    }
    return count;
}

