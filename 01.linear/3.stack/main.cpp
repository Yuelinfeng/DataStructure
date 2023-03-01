#include <iostream>
#include "arrayStack.h"
#include "linkStack.h"

void test01()
{
    ArrayStack * stack = createArrayStack(100);
    for (int i = 1; i <= 100; ++i) {
        pushArrayStack(stack,i);
    }
    printArrayStack(stack);
    pushArrayStack(stack,101);
    std::cout << stack->data[stack->top] << std::endl;
    pushArrayStack(stack, 102);
    for (int i = 0; i < 50; ++i) {
        popArrayStack(stack);
    }
    printArrayStack(stack);
    releaseArrayStack(stack);
}

void test02()
{
    LinkStack *stack = createLinkStack();
    for (int i = 0; i < 5; ++i) {
        pushLinkStack(stack,i + 10);
    }
    printLinkStack(stack);
    releaseLinkStack(stack);
}

int main() {
    test02();
    return 0;
}
