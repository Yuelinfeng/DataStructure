//
// Created by 25328 on 2023/2/20.
//

#ifndef DATASTRUCTURE_BSTREE_H
#define DATASTRUCTURE_BSTREE_H
/*
 * 二叉搜索树
 * 特点：
 *      1. 度为二的节点
 *      2. 左孩子永远小于该节点，右孩子永远大于该节点
 * */

/*
 * 节点，数据域、左孩子、右孩子
 * */
using Element = int;
typedef struct bSNode
{
    bSNode *left{};
    bSNode *right{};
    Element data{};
}BSNode;

/*
 * 树的结构
 * */
typedef struct BSTree
{
    BSNode *root{};   // 头节点
    int count{};          // 节点数
}BSTree;

// 创建BSTree的结构
BSTree *createBSTree();
// 释放BSTree及其节点
void releaseBSTree(BSTree *tree);
// 按照二分搜索树的规则插入数据（非递归方式）
int insertBSTreeNode(BSTree *tree, Element data);
// 在二分搜索树中，查找值为e的节点
BSNode *searchBSTreeNode(BSTree *tree, Element e);


#endif //DATASTRUCTURE_BSTREE_H
