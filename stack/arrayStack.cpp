//
// Created by 乐林风 on 2023/1/13.
//

#include "arrayStack.h"
#include <iostream>
ArrayStack *createArrayStack(int size)
{
    ArrayStack *newArrayStack = new ArrayStack;
    newArrayStack->data = new Element[size];
    if (newArrayStack->data == nullptr)
    {
        std::cout << "Create failed ......" << std::endl;
        return nullptr;
    }
    newArrayStack->MaxSize = size;
    newArrayStack->top = -1;
    return newArrayStack;
}
/*数据有效范围：[0, 1, 2, ... ,max-1] */
int pushArrayStack(ArrayStack *ArrayStack, int ele)
{
    if (ArrayStack->top >= ArrayStack->MaxSize - 1) {
        std::cout << "ArrayStack is full, push error......" << std::endl;
        return -1;
    }
    ArrayStack->data[++ArrayStack->top] = ele;
    return 0;
}

bool emptyArrayStack(ArrayStack *ArrayStack)
{
    if (ArrayStack->top < 0) return true;
    else return false;
}

int popArrayStack(ArrayStack *ArrayStack)
{
    if (emptyArrayStack(ArrayStack)) {
        std::cout << "ArrayStack is empty, pop error......" << std::endl;
        return -1;
    }
    ArrayStack->data[ArrayStack->top] = -1;
    ArrayStack->top--;
    return 0;
}

int popArrayStack(ArrayStack *ArrayStack, Element *e) {
    if (emptyArrayStack(ArrayStack)) {
        std::cout << "UnderFlow, pop error......" << std::endl;
        return -1;
    }
    *e = ArrayStack->data[ArrayStack->top--];
    return 0;
}

void releaseArrayStack(ArrayStack *ArrayStack)
{
    delete[] ArrayStack->data;
    delete ArrayStack;
}

void printArrayStack(ArrayStack *ArrayStack)
{
    for (int i = ArrayStack->top; i >= 0; --i) {
        std::cout << ArrayStack->data[i] << "\t";
    }
    std::cout << std::endl;
}


