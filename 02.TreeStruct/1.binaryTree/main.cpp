//
// Created by 25328 on 2023/2/5.
//
#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
    TreeNode *a = createTreeNode('A');
    TreeNode *b = createTreeNode('B');
    TreeNode *c = createTreeNode('C');
    TreeNode *d = createTreeNode('D');
    TreeNode *e = createTreeNode('E');
    TreeNode *f = createTreeNode('F');
    TreeNode *g = createTreeNode('G');
    TreeNode *h = createTreeNode('H');
    TreeNode *k = createTreeNode('K');
    BinaryTree *tree = createBinaryTree(a);
    insertBinaryTree(tree,a,b, e);
    insertBinaryTree(tree,b, nullptr,c);
    insertBinaryTree(tree,c,d, nullptr);
    insertBinaryTree(tree,e, nullptr,f);
    insertBinaryTree(tree,f,g, nullptr);
    insertBinaryTree(tree,g,h,k);

    cout << "层序遍历：";
    floorOrderBTreeRecur(tree);
    cout << endl;
    cout << "先序遍历：";
    preOrderBTreeRecur(tree->root);
    cout << endl;
    preOrderBTreeNoRecur(tree);
    cout << endl;
    cout << "中序遍历：";
    midOrderBTreeRecur(tree->root);
    cout << endl;
    midOrderBTreeNoRecur(tree);
    cout << endl;
    cout << "后序遍历：";
    lastOrderBTreeRecur(tree->root);
    cout << endl;
    lastOrderBTreeNoRecur(tree);
    cout << endl;
    cout << "释放二叉树（后序）：";
    releaseBinaryTree(tree);
    cout << endl;
    return  0;
}