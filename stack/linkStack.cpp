//
// Created by 25328 on 2023/1/20.
//
#include <iostream>
#include "linkStack.h"

LinkStack *createLinkStack() {
    LinkStack *stack = new LinkStack;
    if(stack == nullptr) {
        std::cout << "Create LinkStack failed......" << std::endl;
    }
    stack->top = nullptr;
    stack->count = 0;
    return stack;
}

int pushLinkStack(LinkStack *stack, Element ele) {
    stackNode *node = new stackNode;
    if (node == nullptr) {
        std::cout << "pushLinkStack failed......" << std::endl;
        return -1;
    }
    node->element = ele;
    node->next = stack->top;
    stack->top = node;
    stack->count++;
    return 0;
}

int popLinkStack(LinkStack *stack) {
    if (stack->top == nullptr) {
        std::cout << "popLinkStack error......" << std::endl;
        return -1;
    }
    stackNode *tmp = stack->top;
    stack->top = tmp->next;
    delete tmp;
    stack->count--;
    return 0;
}

int popLinkStack(LinkStack *stack, Element *e) {
    if (stack->top == nullptr) {
        std::cout << "popLinkStack error......" << std::endl;
        return -1;
    }
    *e = stack->top->element;
    stackNode *tmp = stack->top;
    stack->top = tmp->next;
    delete tmp;
    stack->count--;
    return 0;
}

void releaseLinkStack(LinkStack *stack) {
    if (stack) {
        while (stack->top) {
//            stackNode *tmp = stack->top;
//            stack->top = tmp->next;
//            delete tmp;
//            stack->count--;
            popLinkStack(stack);
        }
    }
    delete stack;
}

void printLinkStack(LinkStack *stack) {
    stackNode *ptr = stack->top;
    while (ptr) {
        std::cout << ptr->element << '\t';
        ptr = ptr->next;
    }
}

