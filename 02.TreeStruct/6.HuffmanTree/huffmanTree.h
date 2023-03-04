//
// Created by 25328 on 2023/3/1.
//

#ifndef DATASTRUCTURE_HUFFMANTREE_H
#define DATASTRUCTURE_HUFFMANTREE_H
/*
 * Huffman树表示的是树中各节点的带权值路径最小值
 * 采用顺序存储方式来表示Huffman树
 * 因为元素有n个叶子节点，所以有总共有2n-1个节点
 * 数组的0号位置空，申请2n个
 * */
// Huffman树的节点结构
typedef struct {
    int weight;         // 节点的权值
    int lChild,rChild;  // 指向孩子节点的索引号（数组下标）
    int parent;         // 存储该节点的父节点的索引号，0表示不存在父节点，没有根节点
}HuffmanNode, *HuffmanTree;
// 构建Huffman树
HuffmanTree createHuffmanTree(const int *w, int n); // w表示权值, n表示n个节点
void releaseHuffmanTree(HuffmanTree tree);

typedef char *HuffmanCode;
// 依据Huffman树，产生n个字符的Huffman编码
HuffmanCode *createHuffmanCode(HuffmanTree tree, int n);
void releaseHuffmanCode(HuffmanCode *codes, int n);
#endif //DATASTRUCTURE_HUFFMANTREE_H
