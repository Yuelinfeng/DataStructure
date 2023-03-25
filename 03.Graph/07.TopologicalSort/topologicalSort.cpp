//
// Created by 25328 on 2023/3/22.
//

#include <cstring>
#include "topologicalSort.h"

int TopologicalSort(AGraph *graph) {
    int *inDegree = new int[graph->nodeNum];
    // 1. 将有向图的所有出度边 更新到 入度记录表
    memset(inDegree, 0, sizeof(int) * graph->nodeNum);
    for (int i = 0; i < graph->nodeNum; ++i) {
        ArcEdge *edge = graph->nodes[i].firstEdge;
        while (edge) {
            ++inDegree[edge->no];
            edge = edge->next;
        }
    }
    // 2. 查找入度记录表里，度为0的顶点，入栈（也可以入队）
    int *stack;
    int top = -1;
    stack = new int[graph->nodeNum];
    for (int i = 0; i < graph->nodeNum; ++i) {
        if (inDegree[i] == 0)
            stack[++top] = i;
    }
    // 3. 根据任务栈里的数据，弹出第一个任务，将这个任务对应的节点，相关的边删除
    // 更新入度记录表，如果发现当前入度值为0，就入任务栈
    int index;       // 任务编号（顶点）
    int count = 0;   // 从栈中弹出任务的个数
    while (top != -1) {
        index = stack[top--];
        count++;
        visitAGraphNode(&graph->nodes[index]);
        // 更新入度记录表
        ArcEdge *edge = graph->nodes[index].firstEdge;
        while (edge) {
            --inDegree[edge->no];
            // 如果在更新入度记录表时，发现是0了，就更新到任务栈
            if (inDegree[edge->no] == 0) {
                stack[++top] = edge->no;
            }
            edge = edge->next;
        }
    }
    delete[] stack;
    delete[] inDegree;
    if (count == graph->nodeNum)
        return 0;
    else
        return 1;
}
