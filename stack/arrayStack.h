//
// Created by 乐林风 on 2023/1/13.
//

#ifndef ArrayStack_ARRAYArrayStack_H
#define ArrayStack_ARRAYArrayStack_H
using Element=int;
typedef struct
{
    Element* data;
    int top;
    int MaxSize;
}ArrayStack;

ArrayStack* createArrayStack(int size);

int pushArrayStack(ArrayStack* ArrayStack, int ele);

void printArrayStack(ArrayStack* ArrayStack);

bool emptyArrayStack(ArrayStack* ArrayStack);

int popArrayStack(ArrayStack* ArrayStack);
int popArrayStack(ArrayStack* ArrayStack, Element *e);

void releaseArrayStack(ArrayStack* ArrayStack);
#endif //ArrayStack_ARRAYArrayStack_H
