//
// Created by 25328 on 2023/2/20.
//
#include "BSTree.h"
#include <iostream>
using namespace std;
int main() {
    BSTree *tree = createBSTree();
    insertBSTreeNode(tree,8);
    insertBSTreeNode(tree,3);
    insertBSTreeNode(tree,10);
    insertBSTreeNode(tree,14);
    insertBSTreeNode(tree,13);
    insertBSTreeNode(tree,6);
    insertBSTreeNode(tree,4);
    insertBSTreeNode(tree,7);
    Element e = 5;
    BSNode *node = searchBSTreeNode(tree,e);
    if (node) {
        cout << node->data << endl;
    }else {
        ::printf("%d不存在......",e);
    }
    releaseBSTree(tree);
}