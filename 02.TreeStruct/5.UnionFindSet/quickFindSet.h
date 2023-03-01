//
// Created by 25328 on 2023/2/28.
//

#ifndef DATASTRUCTURE_QUICKFINDSET_H
#define DATASTRUCTURE_QUICKFINDSET_H
/* 查并集的QuickFind的算法下的结构定义
 * 每一个元素都村有一个编号，只要编号一样，就代表一个集团的人
 * 合并时，就是把另外一个团队的人的老大改为这个团队的老大
 * */
typedef int Element;
typedef struct
{
    Element *data;  // 具体数据，利用索引建立数据关系
    int n;          // 数量
    int *groupID;   // 组信息
}QuickFindSet;

QuickFindSet *createQuickFindSet(int n);
void releaseQuickFinSet(QuickFindSet *setQF);
// 初始化并查集，设置元素值对应的编号
void initQuickFindSet(QuickFindSet *setQF, const Element *data, int n);
// 查：判断两个元素是不是同一组
int isSameQF(QuickFindSet *setQF, Element a, Element b);
// 并
void unionQF(QuickFindSet *setQF, Element a, Element b);
#endif //DATASTRUCTURE_QUICKFINDSET_H
