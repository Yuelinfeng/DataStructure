//
// Created by 25328 on 2023/2/20.
//
#include <iostream>
#include "BSTree.h"

/*
 * 创建BSTree
 * */
BSTree *createBSTree() {
    BSTree *tree = new BSTree;
    return tree;
}

/*
 * 先释放节点，然后释放BSTree
 * */
// 后序遍历释放节点
static void deleteNode(BSNode *node) {
    if (!node) return;
    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
}
void releaseBSTree(BSTree *tree) {
    if (tree) {
        deleteNode(tree->root);
    }
    delete tree;
}

// 插入
static BSNode *createBSNode(Element e) {
    BSNode *node = new BSNode;
    node->data = e;
    return node;
}
/*
 * 1. 找到待插入点的位置
 * 2. 分配节点
 * 3. 将新节点放入待插入位置的节点的左（右）
 * 因为要保留待插入点的位置，使用双指针
 * */
int insertBSTreeNode(BSTree *tree, Element data) {
    if (tree) {
        BSNode *cur = tree->root;
        BSNode *pre = nullptr;
        while (cur) {
            pre = cur;
            if (data > cur->data) {
                cur = cur->right;
            } else if (data < cur->data) {
                cur = cur->left;
            }else {
                std::cout << "该节点已经存在......" << std::endl;
            }
        }
        // 创建节点
        BSNode *node = createBSNode(data);
        if (pre) {
            if (node->data > pre->data) {
                pre->right = node;
            }else{
                pre->left = node;
            }
        }
        else{
            tree->root = node;
        }
    }
    return 0;
}

/*
 * 1. 小左 大右
 * */
BSNode *searchBSTreeNode(BSTree *tree, Element e) {
    BSNode *node = tree->root;
    while (node) {
        if (node->data > e) {   // 小往左边查
            node = node->left;
        }else if (node->data < e) { //大往右边查
            node = node->right;
        }else {
            return node;
        }
    }
    return nullptr;
}
