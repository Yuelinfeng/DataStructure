//
// Created by 乐林风 on 2023/1/5.
//

#ifndef TEST_SQLIST_H
#define TEST_SQLIST_H
typedef int Element;
constexpr int SUCCESS = 0;
constexpr int ERROR = -1;
class SqList {
private:
    Element* elem; //指向动态线性表首地址的指针
    int len;       //目前已使用的长度
    unsigned capacity;  //可以容量的长度
public:
    //创建线性表
    explicit SqList(int n);
    //释放线性表
    void release();
    //得到指定位置的元素
    int getElement(Element ele,int& pos);
    //插入元素
    int insertElement(Element& ele);
    //指定位置插入元素
    int insertElement(Element ele,int pos);
    //释放指定位置元素
    int deleteElement(int n);
    //释放指定元素
//    int deleteElement(Element& n);
    //打印线性表中的元素
    void print();
    //元素的位置
    int locateElemnt(Element ele,int& pos);
    ~SqList();
};


#endif //TEST_SQLIST_H
