//
// Created by 25328 on 2023/3/1.
//

#include "huffmanTree.h"
#include <iostream>
#include <cstring>

static void selectMinNode(HuffmanTree tree, int num, int *s1, int *s2)
{
    int min = 0;    // 假设最小值的索引号
    if (!tree) return;
    // 找到第一个父节点为0的节点，假设为最小值
    for (int i = 1; i <= num; ++i) {
        if (tree[i].parent == 0)
        {
            min = i;
            break;
        }
    }
    for (int i = 1; i <= num; ++i) {
        if (tree[i].parent == 0)
            if (tree[i].weight < tree[min].weight)
                min = i;
    }
    *s1 = min;

    for (int i = 1; i <= num; ++i) {
        if (tree[i].parent == 0 && i != *s1)
        {
            min = i;
            break;
        }
    }
    for (int i = 1; i <= num; ++i) {
        if (tree[i].parent == 0 && i != *s1)
            if (tree[i].weight < tree[min].weight)
                min = i;
    }
    *s2 = min;

}
HuffmanTree createHuffmanTree(const int *w, int n) {
    HuffmanTree tree;
    int m = 2 * n - 1;
    // 1. 申请顺序数组，元素个数是2n-1，采用0号索引的位置不用，保证0值作为一个状态标志
    tree = new HuffmanNode[m+1];
    // 2. 初始化，将每个节点的左右孩子，父节点初始为0 [0,2n-1]
    for (int i = 1; i <= m; ++i) {
        tree[i].parent = tree[i].lChild = tree[i].rChild = 0;
        tree[i].weight = 0;
    }
    // 3. 设置n个元素的权值
    for (int i = 1; i <= n; ++i) {
        tree[i].weight = w[i - 1];
    }
    // 4. 创造哈夫曼树
    /*
     * 1. 找权值最小的两个节点的索引
     * 2. 合成新的权值，加到数组中
     * 3. 设置新节点的左孩子右孩子
     * 4. 设置最小两个节点的父节点
     * */
    int s1, s2;
    for (int i = n+1; i <= m; ++i) {
        selectMinNode(tree,i-1,&s1,&s2); // 从[0,i]中找最小的两个节点
        tree[i].weight = tree[s1].weight + tree[s2].weight;
        tree[i].lChild = s1; tree[i].rChild = s2;
        tree[s1].parent = tree[s2].parent = i;
    }
    return tree;
}

HuffmanCode *createHuffmanCode(HuffmanTree tree, int n) {
    // 生成了n个字符的编码表，表中每个表项里保存的是这个字符对应的编码空间首地址
    HuffmanCode *codes = new HuffmanCode[n]{nullptr};
    // 对n个字符，查看Huffman树，生成对应的堆空间，将这个空间赋值给codes的位置
    // 逐步字符求Huffman编码
    char *temp = new char [n];
    // 用这个n个字符的编码表，进行从尾到头的编码
    int start; // 尾部
    int p;     //存放当前节点的父节点信息
    int pos;   // 小弟
    for (int i = 1; i <= n; ++i) {
        start = n - 1;
        temp[start] = '\0'; // 字符串的末尾永远为'\0'
        pos = i;            //初始化当前位置
        p = tree[i].parent;  // 当前节点的父节点
        while (p) {
            // 从尾到头编码
            // 0 or 1
            --start; // 从尾部开始
            temp[start] = tree[p].lChild == pos ? '0' : '1';
            pos = p;
            p = tree[p].parent;
        }
        // 保存编码后的字符串
        codes[i-1] = (HuffmanCode) malloc(sizeof(char )*(n - start));
        strcpy(codes[i-1], &temp[start]);
    }
    delete[] temp;
    return codes;
}

void releaseHuffmanCode(HuffmanCode *codes, int n) {
    for (int i = 0; i < n; ++i) {
        if (codes[i]) {
            delete codes[i];
        }
    }
    delete[] codes;
}

void releaseHuffmanTree(HuffmanTree tree) {
    delete tree;
}
