//
// Created by 25328 on 2023/2/27.
//
#include "avlTree.h"
#include <iostream>
using namespace std;
void test01()
{
    Element data[] = {10,20,30,40,50,60,67,80};
    AVLTree *tree = createAVLTree();
    for (int i : data) {
        insertAVLTree(tree,i);
    }
    printf("平衡树的中序遍历：");
    inOrderAVLTree(tree);
    deleteAVLNode(tree, 30);
    printf("平衡树的中序遍历：");
    inOrderAVLTree(tree);
    ::printf("\n平衡二叉树的高度：%d\n",tree->root->height);

    releaseAVLTree(tree);
}
int main() {
    test01();
}