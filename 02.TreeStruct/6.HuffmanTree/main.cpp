//
// Created by 25328 on 2023/3/2.
//
#include "huffmanTree.h"
#include <iostream>
using namespace std;
int test01()
{
    int w[] = {5,29,7,8,14,23,3,11};
    int show[] = {'A','B','C','D','E','F','G','H'};
    HuffmanTree tree = createHuffmanTree(w,sizeof(w)/sizeof(w[0]));
    if (tree) {
        for (int i = 1; i <= 15; ++i) {
            ::printf("%d\t%d\t%d\t%d\t%d\n", i ,tree[i].weight, tree[i].parent, tree[i].lChild, tree[i].rChild);
        }
    }
    HuffmanCode *code = createHuffmanCode(tree,sizeof(w)/sizeof(w[0]));
    for (int i = 0; i < sizeof(w) / sizeof (w[0]);++i) {
        ::printf("%c: %s\n", show[i], code[i]);
    }
    releaseHuffmanCode(code,sizeof(w)/sizeof(w[0]));
    releaseHuffmanTree(tree);
    return 0;
}
void test02()
{
    int a = 1, b = 1, c = 1, d= 2, m = 2, n = 2;
    n = (m = a + b, c + d, 10);
    cout << n << endl;
}
int main()
{
    test02();
}