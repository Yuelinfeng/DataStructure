//
// Created by 25328 on 2023/1/21.
//
#include <iostream>
#include "ArrayQueue.h"

ArrayQueue *createArrayQueue() {
    ArrayQueue *queue = new ArrayQueue;
    queue->front = queue->rear = 0;
    return queue;
}

void releaseArrayQueue(ArrayQueue *queue)
{
    if (queue)
    {
        delete queue;
    }
}

int enArrayQueue(ArrayQueue *queue, Element e) {
    //先判断队列满不满
    if ((queue->rear + 1) % MaxQueue == queue->front)
    {
        std::cout << "Queue full..." << std::endl;
        return -1;
    }
    queue->rear = (queue->rear+1) % MaxQueue;
    queue->data[queue->rear] = e;
    return 0;
}

int deArrayQueue(ArrayQueue *queue, Element* e) {
    if (queue->rear == queue->front)
    {
        std::cout << "Queue empty..." << std::endl;
        return -1;
    }
    queue->front = (queue->front + 1) % MaxQueue;
    *e = queue->data[queue->front];
    return 0;
}


