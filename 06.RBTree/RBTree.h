//
// Created by 25328 on 23/4/7.
//

#ifndef DATASTRUCTURE_RBTREE_H
#define DATASTRUCTURE_RBTREE_H
enum RBColor {
    RED
    ,BLACK
};
typedef int KeyType;
/* 红黑树的节点结构 */
struct RBNode {
    char color{};
    KeyType key{};
    struct RBNode *left{};
    struct RBNode *right{};
    struct RBNode *parent{};
};
struct RBTree {
    struct RBNode *root{};
    int count{};
};

// 创建
RBTree *createRBTree();
void insertRBNode(RBTree *tree, KeyType key);
void releaseRBTree(RBTree *tree, RBNode *node);
// 显示红黑树
void printRBTree(RBNode *node, int key, int dir);
#endif //DATASTRUCTURE_RBTREE_H
