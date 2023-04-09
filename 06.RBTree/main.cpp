//
// Created by 25328 on 23/4/7.
//
#include <cstdio>
#include "RBTree.h"
void test01() {
    int data[] = {55,40,65,60,75,57,63,56};
    RBTree *tree = createRBTree();
    for (int i : data) {
        insertRBNode(tree, i);
    }
    printf("%d\n",tree->count);
    printRBTree(tree->root,tree->root->key,0);
    releaseRBTree(tree,tree->root);
}
int main()
{
    test01();
}