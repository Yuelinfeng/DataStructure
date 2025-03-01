#include <cstdio>
#include "linkList.h"

#include <wchar.h>

LinkList *createLinkList() {
    LinkList *list;
    list = new LinkList;
    if (nullptr == list) {
        printf("分配失败.....\n");
        return nullptr;
    }
    list->len = 0;
    list->head.ele = 0;
    list->head.next = nullptr;
    return list;
}


void releaseLinkList(LinkList *linkList) {
    int cnt = 0;
    if (linkList) {
        Node* p = &linkList->head;
        //头删法 head node1 node2 NULL
        while (p->next) {
            Node *tmp = p->next;
            p->next = tmp->next;
            delete tmp;
            cnt++;
        }
    }
    printf("release %d node!\n", cnt);
    delete linkList;
}

//先备份
int insertLinkList(LinkList *linkList, int pos, Element e) {
    if (!linkList) return -1;
    if (pos < 1 || pos > linkList->len + 1)
    {
        printf("insert pos invalid......\n");
        return -1;
    }
    Node* ptr = &linkList->head;
    for (int i = 1; i < pos; ++i) {
        ptr = ptr->next;
    }
    //此时ptr指向插入位置的前一个元素
    Node *n = new Node;
    if (nullptr == n) {
        printf("分配失败......\n");
        return -1;
    }
    n->ele = e;
    n->next = ptr->next;
    ptr->next = n;
    linkList->len++;
    return 0;
}

int deleteLinkList(LinkList *linkList, Element e) {
    if (!linkList) return -1;
    Node *p = &linkList->head;
    while (p->next) {
        if (e == p->next->ele) {
            Node *tmp = p->next;
            p->next = tmp->next;
            delete tmp;
            linkList->len--;
            return 0;
        }
        p = p->next;
    }
    return 1;
}

void showLinkList(LinkList *linkList) {
    Node *p = &linkList->head;
    while (p->next)
    {
        printf("%d\t",p->next->ele);
        p = p->next;
    }
    printf("\n");
}

// 尾插法
int insertLinkList(LinkList *linkList, Element e) {
    Node *p = &linkList->head;
    while (p->next) {
        p = p->next;
    }
    p->next = new Node;
    p->next->ele = e;
    linkList->len++;
    return 0;
}

// 头插法
int insertLinkListHead(LinkList *linkList, Element e)
{
    Node *p = &linkList->head;
    Node *tmp = new Node;
    tmp->ele = e;
    tmp->next = p->next;
    p->next = tmp;
    return 0;
}

// 链表反转
void reverseLinkList(LinkList *linkList)
{
    /*方法一：原地反转*/
    // 连 掉 接 姨
    Node *head = &linkList->head;

    Node *beg = linkList->head.next;
    Node *end = beg->next;
    while (end != nullptr)
    {
        beg->next = end->next;
        end->next = head->next;
        head->next = end;
        end = beg->next;
    }
}

// 头插法——链表反转
void headReverse(LinkList *linkList)
{
    /*方法二：头插法*/
    Node *head = &linkList->head;
    Node *p = head->next;
    Node *q = nullptr;
    head->next = nullptr;
    while (p)
    {
        q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
}