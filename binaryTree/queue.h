#ifndef QUEUE_H
#define QUEUE_H
#include "BinaryTree.h"
//节点结构
struct queueNode {
    treeNode* node;
    queueNode* next;
    explicit queueNode(TreeNode *node = nullptr, queueNode *next = nullptr)
        : node(node)
        , next(next)
    {};
};
//队列结构及操作
class linkQueue
{
    using Element = treeNode;
private:
    queueNode *front{};
    queueNode *rear{};
    int count{};
public:
    linkQueue();
    ~linkQueue();

    int intoQueue(Element *node);
    treeNode * outQueue();
    bool empty();
};
#endif