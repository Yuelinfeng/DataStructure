//
// Created by 25328 on 2023/2/7.
//

#include <cstdio>
#include "threadedTree.h"

ThreadBTree *createThreadedBTree(TBTNode *root) {
    ThreadBTree * tree = new ThreadBTree;
    tree->root = root;
    (tree->root == nullptr) ? tree->count = 0 : tree->count = 1;
    return tree;
}

static void desOrder(ThreadBTree *tree, TBTNode *node) {
    if (node) {
        if (node->lTag == 0) {
            desOrder(tree,node->left);
        }
        if (node->rTag == 0) {
            desOrder(tree,node->right);
        }
        delete node;
        tree->count--;
    }
}
void releaseThreadedBTree(ThreadBTree *tree) {
    if (tree) {
        desOrder(tree,tree->root);
        printf("\n还剩%d个节点",tree->count);
        delete tree;
    }
}

TBTNode *createTBTNode(Element e) {
    TBTNode *node = new TBTNode;
    node->data = e;
    return node;
}

void insertThreadedBTree(ThreadBTree *tree, TBTNode *parent, TBTNode *left, TBTNode *right) {
    if (tree == nullptr || parent == nullptr) return;
    parent->left = left;
    parent->right = right;
    if (left) tree->count++;
    if (right) tree->count++;
}

void visitTBTNode(TBTNode *node) {
    if (node) {
        printf("%c,\t",node->data);
    }
}

// 线索化二叉树
static TBTNode *pre = nullptr;
static void inOrderThread(TBTNode *node) {
    if (node) {
        inOrderThread(node->left);
        if (node->left == nullptr) {
            node->lTag = 1;
            node->left = pre;
        }
        if (pre && pre->right == nullptr) {
            pre->rTag = 1;
            pre->right = node;
        }
        pre = node;
        inOrderThread(node->right);
    }
}

// 中序遍历线索二叉树
void inOrderThreadedTree(ThreadBTree *tree) {
    if (tree) {
        // 线索化二叉树
        inOrderThread(tree->root);
        // 遍历
        inOrderTBTree(tree);
    }
}

// 中序遍历线索二叉树
void inOrderTBTree(ThreadBTree *tree) {
    TBTNode *node = tree->root;
    while (node) {
        while (!node->lTag) {
            node = node->left;
        }
        visitTBTNode(node);
        while (node->rTag && node->right) {
            node = node->right;
            visitTBTNode(node);
        }
        node = node->right;
    }
}