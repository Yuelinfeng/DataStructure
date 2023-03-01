//
// Created by 25328 on 2023/1/21.
//

#ifndef QUEUE_ARRAYQUEUE_H
#define QUEUE_ARRAYQUEUE_H
using Element = int;
constexpr int MaxQueue = 5;
typedef struct
{
    Element data[MaxQueue];
    int front;
    int rear;
}ArrayQueue;

ArrayQueue *createArrayQueue();
void releaseArrayQueue(ArrayQueue *queue);

int enArrayQueue(ArrayQueue *queue, Element e);

int deArrayQueue(ArrayQueue *queue, Element* e);
#endif //QUEUE_ARRAYQUEUE_H
