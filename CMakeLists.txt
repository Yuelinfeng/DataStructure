cmake_minimum_required(VERSION 3.24)
project(DataStructure CXX C)#这里可以不写C 和 CXX，但是不能只写一个

#设置C++的编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#设置C的编译选项
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")



IF(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexec-charset=GBK")
ENDIF()
# 动态线性表
add_executable(1-1seqList 01.linear/1.seqList 01.linear/1.seqList/main.cpp 01.linear/1.seqList/SqList.cpp)
# 链表
add_executable(1-2linkList 01.linear/2.LinkList 01.linear/2.LinkList/linkList.cpp 01.linear/2.LinkList/main.cpp)
# 栈
add_executable(1-3stack 01.linear/3.stack/arrayStack.cpp 01.linear/3.stack/linkStack.cpp 01.linear/3.stack/main.cpp)
# 队列
add_executable(1-4queue 01.linear/4.queue 01.linear/4.queue/ArrayQueue.cpp 01.linear/4.queue/linkQueue.cpp 01.linear/4.queue/main.cpp)
# 二叉树
add_executable(2-1binaryTree 02.TreeStruct/1.binaryTree 02.TreeStruct/1.binaryTree/BinaryTree.cpp 02.TreeStruct/1.binaryTree/main.cpp)
# 线索二叉树
add_executable(2-2threadTree 02.TreeStruct/2.ThreadedTree 02.TreeStruct/2.ThreadedTree/threadedTree.cpp 02.TreeStruct/2.ThreadedTree/main.cpp)
# 二叉搜索树
add_executable(2-3binarySearchTree 02.TreeStruct/3.BinarySearchTree 02.TreeStruct/3.BinarySearchTree/BSTree.cpp 02.TreeStruct/3.BinarySearchTree/BSTree.h 02.TreeStruct/3.BinarySearchTree/main.cpp)
# 平衡二叉树
add_executable(2-4avlTree 02.TreeStruct/4.AVLTree 02.TreeStruct/4.AVLTree/avlTree.cpp 02.TreeStruct/4.AVLTree/avlTree.h 02.TreeStruct/4.AVLTree/main.cpp)
# 查并集
add_executable(2-5unionFindSet 02.TreeStruct/5.UnionFindSet 02.TreeStruct/5.UnionFindSet/quickFindSet.cpp 02.TreeStruct/5.UnionFindSet/quickFindSet.h 02.TreeStruct/5.UnionFindSet/main.cpp 02.TreeStruct/5.UnionFindSet/quickUnion.cpp 02.TreeStruct/5.UnionFindSet/quickUnion.h)
#哈夫曼树
add_executable(2-6HuffmanTree 02.TreeStruct/6.HuffmanTree/huffmanTree.cpp 02.TreeStruct/6.HuffmanTree/huffmanTree.h 02.TreeStruct/6.HuffmanTree/main.cpp)

#邻接矩阵
add_executable(3-1MatrixGraph 03.Graph/01.MatrixGraph/matrixGraph.cpp 03.Graph/01.MatrixGraph/matrixGraph.h 03.Graph/base.h 03.Graph/01.MatrixGraph/main.cpp)
add_executable(3-2AdjacentGraph 03.Graph/02.AdjacentGraph/adjacentGraph.cpp 03.Graph/02.AdjacentGraph/adjacentGraph.h 03.Graph/base.h 03.Graph/02.AdjacentGraph/main.cpp)

#十字链表
add_executable(3-3CrossLinkGraph 03.Graph/03.CrossLinkGraph/crossLinkGraph.cpp 03.Graph/03.CrossLinkGraph/crossLinkGraph.h 03.Graph/03.CrossLinkGraph/main.cpp)
#多重邻接表
add_executable(3-4AdjacencyMultiList 03.Graph/04.AdjacencyMultiList/adjacencyMultiList.cpp 03.Graph/04.AdjacencyMultiList/adjacencyMultiList.h)
#最小生成树
add_executable(3-5MiniTree 03.Graph/05.MiniTree/Kruskal.cpp 03.Graph/05.MiniTree/Kruskal.h 03.Graph/05.MiniTree/main.cpp)