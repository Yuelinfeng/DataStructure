//
// Created by 25328 on 2023/2/11.
//
#include <iostream>
#include "threadedTree.h"
using namespace std;
int main() {
    TBTNode *a = createTBTNode(65);
    ThreadBTree *tree = createThreadedBTree(a);
    TBTNode *b = createTBTNode(66);
    TBTNode *c = createTBTNode(67);
    TBTNode *d = createTBTNode(68);
    TBTNode *e = createTBTNode(69);
    insertThreadedBTree(tree,a,b,c);
    insertThreadedBTree(tree,b,d,e);
    insertThreadedBTree(tree,c, nullptr, nullptr);
    insertThreadedBTree(tree,d, nullptr, nullptr);
    insertThreadedBTree(tree,e, nullptr, nullptr);
    inOrderThreadedTree(tree);
    releaseThreadedBTree(tree);
}