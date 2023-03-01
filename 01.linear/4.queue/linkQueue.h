//
// Created by 25328 on 2023/1/28.
//

#ifndef QUEUE_LINKQUEUE_H
#define QUEUE_LINKQUEUE_H
using Element = int;
//链式节点类型
typedef struct queNode {
    Element data{};
    queNode* next = nullptr;
};
//链队列结构类型
typedef struct {
    queNode *front;
    queNode *rear;
    int cnt;
}linkQueue;

linkQueue* createLinkQueue();
void releaseLinkQueue(linkQueue* queue);

int enLinkQueue(linkQueue *queue, Element e);

int deLinkQueue(linkQueue *queue, Element *e);
#endif //QUEUE_LINKQUEUE_H
