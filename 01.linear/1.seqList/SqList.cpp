//
// Created by 乐林风 on 2023/1/5.
//

#include "SqList.h"
#include <iostream>
using namespace std;
SqList::SqList(int n)
    : len(0)
    , capacity(abs(n))
{
    elem = new Element[capacity]{};
}
void SqList::release() {
    delete[] elem;
}

int SqList::getElement(Element ele, int& pos) {
    if (pos < 1 || pos > len + 1)
        return ERROR;
    ele = elem[pos - 1];
    return SUCCESS;
}

int SqList::insertElement(Element &ele) {
    if (len + 1 > capacity) //扩容
    {
        Element *tmp = new Element[capacity*2];
        for (int i = 0; i <= len; ++i)
            tmp[i] = elem[i];
        release();
        elem = tmp;
        elem[len + 1] = ele;
    }
    else
    {
        elem[len++] = ele;
    }
    return SUCCESS;
}

int SqList::insertElement(Element ele, int pos) {
    if (len + 1 > capacity)
    {
        Element *tmp = new Element[capacity * 2];
        for (int i = 0,j = 0; i < len + 1; ++i,++j) {
            if (i == pos - 1)
            {
                tmp[i] = ele;
                j--;
            }
            else tmp[i] = elem[j];
        }
        release();
        elem = tmp;
        capacity *= 2;
    }
    else
    {
        for (int i = len; i >= pos - 1; --i)
            elem[i + 1] = elem[i];
        elem[pos - 1] = ele;
    }
    len++;
    return SUCCESS;
}

int SqList::deleteElement(int pos) {
    if (pos < 1 || pos > len)
        return ERROR;
    for (int i = pos - 1; i <= len; ++i) {
        elem[i] = elem[i + 1];
    }
    len--;
    return SUCCESS;
}

//int SqList::deleteElement(Element &n) {
//    for (int i = 0; i <= len; ++i) {
//        if (elem[i] == n)
//        {
//            for (int j = i; j <= len; ++j) {
//                elem[j] = elem[j + 1];
//            }
//            return SUCCESS;
//        }
//    }
//    return ERROR;
//}

void SqList::print() {
    for (int i = 0; i < len; ++i) {
        cout << elem[i] << "\t";
    }
    cout << endl;
}

int SqList::locateElemnt(Element ele,int& pos) {
    for (int i = 0; i <= len; ++i) {
        if (elem[i] == ele)
        {
            pos = i + 1;
            return SUCCESS;
        }
    }
    return ERROR;
}

SqList::~SqList() = default;
