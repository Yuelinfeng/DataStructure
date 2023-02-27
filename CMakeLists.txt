cmake_minimum_required(VERSION 3.24)
project(DataStructure CXX C)#这里可以不写C 和 CXX，但是不能只写一个

#设置C++的编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#设置C的编译选项
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")



IF(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexec-charset=GBK")
ENDIF()

add_executable(Linear_table Linear_table/main.cpp Linear_table/SqList.cpp)

add_executable(LinkList LinkList/linkList.cpp LinkList/main.cpp)

add_executable(Queue Queue/ArrayQueue.cpp Queue/linkQueue.cpp Queue/main.cpp)

add_executable(Stack Stack/arrayStack.cpp Stack/linkStack.cpp Stack/main.cpp)

add_executable(ThreadedTree ThreadedTree/threadedTree.cpp ThreadedTree/main.cpp)

add_executable(BinaryTree BinaryTree/BinaryTree.cpp BinaryTree/main.cpp)

add_executable(BinarySearchTree BinarySearchTree/BSTree.cpp BinarySearchTree/BSTree.h BinarySearchTree/main.cpp)

add_executable(AVLTree AVLTree/avlTree.cpp AVLTree/avlTree.h AVLTree/main.cpp)