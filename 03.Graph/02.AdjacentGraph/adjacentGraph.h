//
// Created by 25328 on 2023/3/6.
//

#ifndef DATASTRUCTURE_ADJACENTGRAPH_H
#define DATASTRUCTURE_ADJACENTGRAPH_H
/*
 * 图的邻接表，在节点集合中，增加指向边的指针
 * 边节点里包含了下一个和首节点相连接的边
 * */
// 边的结构
struct ArcEdge
{
    int no{};     // （从首节点）其他节点的编号
    int weight{}; // 边的权重
    struct ArcEdge *next{}; // （从首节点指）向下一条边
};
// 顶点的结构
struct ArcNode
{
    int no{};           // 顶点的编号
    char *show{};         // 要显示的内容
    ArcEdge *firstEdge{}; // 当前顶点指向的边
};
// 使用邻接表描述的图
struct AGraph
{
    ArcNode *nodes;     // 图中顶点的集合
    int *visited;       // 是否访问的标记
    int nodeNum;        // 图中顶点的数量
    int edgeNum;        // 图中边的个数
    int directed;       // 是否有向，（建议有向）
};

// 产生n个节点的邻接表的图,n个顶点
AGraph *createAGraph(int n);
void releaseAGraph(AGraph *graph);
/*
 * 初始化邻接表的图
 * */
void initAGraph(AGraph *graph, int num, char **names, int directed);
void addGraphEdge(AGraph *graph, int x, int y, int w);

void resetAGraphVisited(AGraph *graph);
void visitAGraphNode(ArcNode *node);
void DFSAGraphTravel(AGraph *graph, int v);
void BFSAGraphTravel(AGraph *graph, int v);
#endif //DATASTRUCTURE_ADJACENTGRAPH_H
