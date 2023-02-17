//
// Created by 25328 on 2023/1/28.
//

#include "linkQueue.h"
#include <iostream>
linkQueue* createLinkQueue()
{
    linkQueue *queue = new linkQueue;
    queue->front = queue->rear = nullptr;
    queue->cnt = 0;
    return queue;
}

void releaseLinkQueue(linkQueue* queue)
{
    if (queue->front == nullptr)
    {
        std::cout << "queue不存在......" << std::endl;
        return;
    }
    while (queue->front != queue->rear && queue->cnt > 0)
    {
        queNode* tmp = queue->front;
        queue->front = tmp->next;
        delete tmp;
        queue->cnt--;
    }
}

int enLinkQueue(linkQueue *queue, Element e) {
    queNode* node = new queNode;
    node->data = e;
    if (nullptr == queue->rear)
    {
        queue->rear = queue->front = node;
    }
    else
    {
        queNode* tmp = queue->rear;
        tmp->next = node;
        queue->rear = node;
        queue->cnt++;
    }
    return 0;
}

int deLinkQueue(linkQueue *queue, Element *e) {
    if (queue->front == nullptr)
    {
        std::cout << "队列为空..." << std::endl;
        return -1;
    }
    queNode* tmp = queue->front;
    *e = tmp->data;
    queue->front = tmp->next;
    delete tmp;
    return 0;
}

