#include "queue.h"
#include <iostream>
linkQueue::linkQueue() = default;

linkQueue::~linkQueue() {
    while (count > 0) {
        queueNode *tmp = front;
        front = tmp->next;
        printf("%d\t",tmp->node->data);
        delete tmp;
        count--;
    }

}

int linkQueue::intoQueue(linkQueue::Element *node) {
    if (rear == nullptr && node) {
        queueNode *newNode = new queueNode(node);
        rear = front = newNode;
        count++;
    }
    else if (node) {
        queueNode *tmp = rear;
        queueNode *newNode = new queueNode(node);
        tmp->next = newNode;
        rear = newNode;
        count++;
    }
    else {
        std::cout << "Element is empty......" << std::endl;
        return -1;
    }
    return 0;
}

treeNode * linkQueue::outQueue() {
    if (!empty()) {
        queueNode *tmp = front;
        front = tmp->next;
//        treeNode = tmp->node;
        count--;
        return tmp->node;
    }
    else {
        std::cout << "linkQueue is empty......" << std::endl;
        return nullptr;
    }
    return 0;
}


bool linkQueue::empty() {
    if (count == 0) return true;
    return false;
}
