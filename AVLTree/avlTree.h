//
// Created by 25328 on 2023/2/25.
//

#ifndef DATASTRUCTURE_AVLTREE_H
#define DATASTRUCTURE_AVLTREE_H
using Element = int;
// 定义平衡二叉树的节点结构
typedef struct AVLNode
{
    Element data{};
    struct AVLNode *left{};
    struct AVLNode *right{};
    int height{};             // 每个节点的高度
}AVLNode;
// 平衡二叉树的结构
typedef struct AVLTree{
    AVLNode *root{};
    int count{};
}AVLTree;

// 产生平衡二叉树
AVLTree *createAVLTree();
// 释放二叉树
void releaseAVLTree(AVLTree *tree);
// 访问
void visitAVLNode(AVLNode *node);
// 平衡二叉树的中序遍历
void inOrderAVLTree(AVLTree *tree);

// 插入元素到AVL树
void insertAVLTree(AVLTree *tree, Element e);
// 删除某个元素
void deleteAVLNode(AVLTree *tree, Element e);

#endif //DATASTRUCTURE_AVLTREE_H
