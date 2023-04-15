//
// Created by 25328 on 23/4/13.
//

#ifndef DATASTRUCTURE_DISKTREE_H
#define DATASTRUCTURE_DISKTREE_H
/*  B树的阶3，说明最大有3颗子树，那么节点最大键值2
 *  在插入节点时，当键值为3时，才会触发分离，申请的时候多申请一个
 * */
#define MaxOrder 3      // m树
typedef int KeyType;    // B树节点键值类型
// B树的节点结构
typedef struct BTNode {
    KeyType key[MaxOrder + 1];
    struct BTNode *ptr[MaxOrder + 1];
    struct BTNode *parent;
    int keyNum;
}BTNode;
// B树结构
typedef struct {
    BTNode *root;
    int count;
}DiskBTree;

/* B树查找的结果集，包含查找成功和失败的信息
 *  ptr : 查找成功，标记当前键值所在的节点地址
 *          查找失败，标记待插入节点（NULL）的父节点
 *  pos : 查找成功，标记键值所在节点的位序索引号
 *          查找失败，标记待插入节点（NULL）的父节点位序号
 *  tag : 1表示查找成功，0表示查找失败
 * */
typedef struct {
    BTNode *ptr;
    int pos;
    int tag;
}Result;

// 初始化B树
DiskBTree *createDiskTree();
// 释放B树
void releaseDiskBTree(DiskBTree *tree);
// 插入节点
void insertKey(DiskBTree *tree, KeyType key);
// 查找B树中key的位置。分查找成功和失败，更新res
void searchBTree(DiskBTree *tree, KeyType key, Result *res);
// 打印
void printBTree(const BTNode *node, int tab);
#endif //DATASTRUCTURE_DISKTREE_H
