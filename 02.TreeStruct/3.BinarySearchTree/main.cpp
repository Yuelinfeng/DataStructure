//
// Created by 25328 on 2023/2/20.
//
#include "BSTree.h"
#include <iostream>
using namespace std;
void test01()
{
    BSTree *tree = createBSTree();
    insertBSTreeNode(tree,8);
    insertBSTreeNode(tree,3);
    insertBSTreeNode(tree,10);
    insertBSTreeNode(tree,14);
    insertBSTreeNode(tree,13);
    insertBSTreeNode(tree,6);
    insertBSTreeNode(tree,4);
    insertBSTreeNode(tree,7);
    Element e = 4;
    BSNode *node = searchBSTreeNode(tree,e);
    if (node) {
        cout << "找到了！" << endl;
    }else {
        ::printf("%d不存在......",e);
    }
    deleteBSTreeNodeNoRecur(tree,4);
    releaseBSTree(tree);
}

void test02()
{
    BSTree *tree = createBSTree();
    insertBSTreeNodeRecur(tree,8);
    insertBSTreeNodeRecur(tree,3);
    insertBSTreeNodeRecur(tree,10);
    insertBSTreeNodeRecur(tree,14);
    insertBSTreeNodeRecur(tree,13);
    insertBSTreeNodeRecur(tree,6);
    insertBSTreeNodeRecur(tree,4);
    insertBSTreeNodeRecur(tree,7);
    cout << heightBSTreeRecur(tree) << endl;
    deleteBSTreeNodeRecur(tree, 3);
    releaseBSTree(tree);
}
int main() {
    test02();
}