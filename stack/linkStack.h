//
// Created by 25328 on 2023/1/20.
//

#ifndef STACK_LINKSTACK_H
#define STACK_LINKSTACK_H
using Element = int;
struct stackNode
{
    Element element{};
    stackNode *next = nullptr;
};

// 链式栈的结构，类似于表头
typedef struct
{
    stackNode *top;
    int count;
}LinkStack;

LinkStack* createLinkStack();

void releaseLinkStack(LinkStack* stack);

int pushLinkStack(LinkStack* stack, Element ele);

int popLinkStack(LinkStack* stack);
int popLinkStack(LinkStack* stack, Element *e);

void printLinkStack(LinkStack* stack);

#endif //STACK_LINKSTACK_H
