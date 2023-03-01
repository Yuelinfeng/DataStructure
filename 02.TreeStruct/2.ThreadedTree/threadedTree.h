//
// Created by 25328 on 2023/2/7.
//

#ifndef DATASTRUCTURE_THREADEDTREE_H
#define DATASTRUCTURE_THREADEDTREE_H
using Element=int;
//线索二叉树的节点结构
typedef struct treeNode {
    Element data{};
    struct treeNode *left{};
    struct treeNode *right{};
    int lTag{};   //0表示left指向左节点，1表示left指向前驱
    int rTag{};   //0表示right指向右节点，1表示right指向后继
}TBTNode;

// 二叉树的描述信息结构
typedef struct {
    TBTNode *root;  // 二叉树的根节点
    int count;      // 二叉树的节点个数
}ThreadBTree;

ThreadBTree *createThreadedBTree(TBTNode *root);
void releaseThreadedBTree(ThreadBTree *tree);
TBTNode *createTBTNode(Element e);
void insertThreadedBTree(ThreadBTree *tree, TBTNode *parent, TBTNode *left, TBTNode *right);
void visitTBTNode(TBTNode *node);

// 中序线索化树，在中序遍历的过程中，建立左右孩子为空指针的值确定
void inOrderThreadedTree(ThreadBTree *tree);
// 按照已经线索化后的树，进行中序遍历
void inOrderTBTree(ThreadBTree *tree);

#endif //DATASTRUCTURE_THREADEDTREE_H
