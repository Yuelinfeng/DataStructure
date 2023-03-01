//
// Created by 25328 on 2023/3/1.
//

#ifndef DATASTRUCTURE_QUICKUNION_H
#define DATASTRUCTURE_QUICKUNION_H

/*
 * 改变了合并和释放
 * */
typedef struct {
    int *data;  // 元素
    int n;      //数量
    int *parent;//每个元素的父节点
    int *size;  // 根节点位置存放集合的个数
}QuickUnionSet;

struct SetStack{
    int index;      //保存路径上的节点索引
    SetStack *next;  // 下一个
};

QuickUnionSet *createQuickUnionSet(int n);
void releaseQuickUnionSet(QuickUnionSet *setQU);
void initQuickUnionSet(QuickUnionSet *setQU, const int *data, int n);
int isSameQU(QuickUnionSet *setQU,int a, int b);
void unionQU(QuickUnionSet *setQU, int a, int b);
#endif //DATASTRUCTURE_QUICKUNION_H
