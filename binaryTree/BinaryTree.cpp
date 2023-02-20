//
// Created by 25328 on 2023/2/5.
//
#include "BinaryTree.h"
#include <queue>
#include <stack>
#include <iostream>
BinaryTree *createBinaryTree(TreeNode *root) {
    BinaryTree *tree = new BinaryTree ();
    if (root) {
        tree->root = root;
        tree->count ++;
    }
    else {
        tree->root = nullptr;
        tree->count = 0;
    }
    return tree;
}
static void desOrder(BinaryTree *tree, TreeNode *node) {
    if (node) {
        desOrder(tree, node->left);
        desOrder(tree, node->right);
        printf("%c\t",node->data);
        delete node;
        tree->count--;
    }
}
void releaseBinaryTree(BinaryTree *tree) {
    if (tree) {
        desOrder(tree, tree->root);
        std::cout << "tree has " << tree->count << " nodes" << std::endl;
        delete tree;
    }
}

TreeNode *createTreeNode(Element e) {
    TreeNode *node = new TreeNode(e);
    return node;
}

void insertBinaryTree(BinaryTree *tree, TreeNode *parent, TreeNode *leftChild, TreeNode *rightChild) {
    if (tree && parent) {
        if (leftChild) {
            parent->left = leftChild;
            tree->count++;
        }
        if (rightChild) {
            parent->right = rightChild;
            tree->count++;
        }
    }
}

void floorOrderBTreeRecur(BinaryTree *tree) {
    std::queue<treeNode*> q;
    q.push(tree->root);
    while (true) {
        treeNode * frontNode = q.front();
        printf("%c\t",frontNode->data);
        q.pop();
        if (frontNode->left)
            q.push(frontNode->left);
        if (frontNode->right)
            q.push(frontNode->right);
        if (q.empty())
            return;
    }
}

void preOrderBTreeRecur(TreeNode *node) {
    if (node == nullptr) return;
    printf("%c\t",node->data);
    preOrderBTreeRecur(node->left);
    preOrderBTreeRecur(node->right);
}

void midOrderBTreeRecur(TreeNode *node) {
    if (node == nullptr) return;
    midOrderBTreeRecur(node->left);
    printf("%c\t",node->data);
    midOrderBTreeRecur(node->right);
}

void lastOrderBTreeRecur(TreeNode *node) {
    if (node == nullptr) return;
    lastOrderBTreeRecur(node->left);
    lastOrderBTreeRecur(node->right);
    printf("%c\t",node->data);
}

std::stack<TreeNode*> stack;
/*
 * 非递归先序遍历
 * 1. 根节点入栈，出栈
 * 2. 先序是先左再右，所以入栈顺序是先右再左
 * 3. 重复
 * */
void preOrderBTreeNoRecur(BinaryTree *tree) {
    if (tree) {
        TreeNode *node = tree->root;
        stack.push(node);
        while (!stack.empty()) {
            if (stack.top()) {
                node = stack.top();
                printf("%c\t",node->data);
                stack.pop();
            }
            if (node->right) {
                stack.push(node->right);
            }
            if (node->left) {
                stack.push(node->left);
            }
        }
    }
}

/*
 * 非递归中序遍历
 *    左 中 右
 * 1. 一直入栈，直到左边找不到了，再出栈，寻找出栈节点的右边
 * 2. 重复
 * */
void midOrderBTreeNoRecur(BinaryTree *tree) {
    if (tree) {
        TreeNode *node = tree->root;
        while (!stack.empty() || node) {
            if (node) {
                stack.push(node);
                node = node->left;
            }else {
                node = stack.top();
                stack.pop();
                printf("%c\t",node->data);
                node = node->right;
            }
        }
    }
}

/*
 * 非递归后序遍历——左 右 中
 *  需要两个栈，主栈和输出栈
 * 1. 根节点先入主栈，然后弹出到输出栈，先左后右入主栈
 * 2. 重复
 * 3. 输出栈全部弹出
 * */
void lastOrderBTreeNoRecur(BinaryTree *tree) {
    if (tree) {
        std::stack<TreeNode*> stack1; // 主栈
        std::stack<TreeNode*> stack2; // 输出栈
        TreeNode *node = tree->root;
        stack1.push(node);
        while (!stack1.empty()) {
            node = stack1.top();
            stack2.push(node);
            stack1.pop();
            if (node->left) {
                stack1.push(node->left);
            }
            if (node->right) {
                stack1.push(node->right);
            }
        }
        while (!stack2.empty()) {
            printf("%c\t",stack2.top()->data);
            stack2.pop();
        }
    }
}

//非递归深度遍历
