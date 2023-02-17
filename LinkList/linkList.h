//
// Created by 乐林风 on 2023/1/7.
//

#ifndef LINKLIST_LINKLIST_H
#define LINKLIST_LINKLIST_H
typedef int Element;
typedef struct node {
    Element ele{};
    struct node *next = nullptr;
}Node;
//表头
typedef struct {
    Node head;
    int len = 0;
}LinkList;
LinkList *createLinkList();
void releaseLinkList(LinkList *linkList);

// 插入节点
int insertLinkList(LinkList *linkList, int pos, Element e);
int insertLinkList(LinkList *linkList, Element e);


// 删除节点
int deleteLinkList(LinkList *linkList, Element e);

// 打印链表
void showLinkList(LinkList *linkList);
#endif //LINKLIST_LINKLIST_H
