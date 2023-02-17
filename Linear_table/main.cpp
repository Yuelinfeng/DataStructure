#include <iostream>
#include "SqList.h"
int main() {
    int n = 5;
    SqList* seq = new SqList(n);
    for (int i = 1; i <= n; ++i) {
        seq->insertElement(i);
    }
    seq->print();
    seq->insertElement(4,4);
    seq->print();
    seq->deleteElement(3);
    int pos;
    seq->getElement(2,pos);
    seq->deleteElement(pos);
    seq->print();
    seq->release();
    delete seq;
    return 0;
}
