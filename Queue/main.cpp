#include <iostream>
#include "ArrayQueue.h"
#include "linkQueue.h"
//测试顺序存储的循环队列
int test01()
{
    ArrayQueue *queue = createArrayQueue();
    Element e;
    for (int i = 0; i < 6; ++i) {
        enArrayQueue(queue,i+100);
    }
    for (int i = 0; i < 4; ++i) {
        deArrayQueue(queue, &e);
        printf("%d\t",e);
    }
    releaseArrayQueue(queue);
    return 0;
}
int test02()
{
    linkQueue *queue = createLinkQueue();
    for (int i = 0; i < 8; ++i) {
        enLinkQueue(queue,i+100);
    }
    Element e;
    for (int i = 0; i < 9; ++i) {
        deLinkQueue(queue,&e);
        printf("%d\t", e);
    }
    releaseLinkQueue(queue);
}
int main() {
//    test01();
    test02();
    return 0;
}
