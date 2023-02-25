//
// Created by 25328 on 2023/2/20.
//
#include <iostream>
#include <algorithm>
#include "BSTree.h"

/*
 * 创建BSTree
 * */
BSTree *createBSTree() {
    BSTree *tree = new BSTree;
    return tree;
}

/*
 * 先释放节点，然后释放BSTree
 * */
// 后序遍历释放节点
static void deleteAllNode(BSNode *node) {
    if (!node) return;
    deleteAllNode(node->left);
    deleteAllNode(node->right);
    delete node;
}
void releaseBSTree(BSTree *tree) {
    if (tree) {
        deleteAllNode(tree->root);
    }
    delete tree;
}

// 插入
static BSNode *createBSNode(Element e) {
    BSNode *node = new BSNode;
    node->data = e;
    return node;
}
/*
 * 1. 找到待插入点的位置
 * 2. 分配节点
 * 3. 将新节点放入待插入位置的节点的左（右）
 * 因为要保留待插入点的位置，使用双指针
 * */
int insertBSTreeNode(BSTree *tree, Element data) {
    if (tree) {
        BSNode *cur = tree->root;
        BSNode *pre = nullptr;
        while (cur) {
            pre = cur;
            if (data > cur->data) {
                cur = cur->right;
            } else if (data < cur->data) {
                cur = cur->left;
            }else {
                std::cout << "该节点已经存在......" << std::endl;
            }
        }
        // 创建节点
        BSNode *node = createBSNode(data);
        if (pre) {
            if (node->data > pre->data) {
                pre->right = node;
            }else{
                pre->left = node;
            }
        }
        else{
            tree->root = node;
        }
        tree->count++;
    }
    return 0;
}

/*
 * 1. 小左 大右
 * */
BSNode *searchBSTreeNode(BSTree *tree, Element e) {
    BSNode *node = tree->root;
    while (node) {
        if (node->data > e) {   // 小往左边查
            node = node->left;
        }else if (node->data < e) { //大往右边查
            node = node->right;
        }else {
            return node;
        }
    }
    return nullptr;
}

/*
 *  双指针
 *  1. 删除度为零的节点
 *      直接删
 *  2. 删除度为一的节点
 *      左孩子（右孩子） 补上
 *  3. 删除度为二的节点
 *      变换为删除度为零的节点(找 后继 或者 前驱）
 * */
//void deleteBSTreeNode(BSTree *tree, Element e) {
//    if (tree) {
//        // 找到该节点
//        BSNode *node = searchBSTreeNode(tree,e);
//        if (node) {
//            // 度为0
//            if (!(node->left || node->right)) {
//                std::cout << node->data << "已删除..." << std::endl;
//                delete node;
//                node = nullptr;
//            }
//            // 度为2
//            else if (node->left && node->right)
//            {
//                // 找右子树中最小的节点
//                BSNode *minNode = node->right;
//                while (minNode) {
//                    if (minNode->left)
//                        minNode = minNode->left;
//                    else
//                        break;
//                }
//                int tmp = node->data;
//                node->data = minNode->data;
//                minNode->data = tmp;
//                deleteBSTreeNode(tree,minNode->data);
//            }
//            // 度为1
//            else {
//                BSNode *tmp = node;
//                if (node->left)
//                    *node = *node->left;
//                else
//                    *node = *node->right;
//                std::cout << tmp->data << "已删除..." << std::endl;
//                delete tmp;
//            }
//        }else{
//            std::cout << "该节点不存在..." << std::endl;
//        }
//    }
//}
static void deleteNode(BSNode *node)
{
    BSNode *mini = node->right;
    BSNode *pre = node;
    while (mini && mini->left) {
        pre = mini;
        mini = mini->left;
    }
    node->data = mini->data;
    if (node == pre) {  // 说明找到的mini是右孩子
        node->right = mini->right;
    }
    else {
        pre->left = mini->right;
    }
    delete mini;
}
void deleteBSTreeNodeNoRecur(BSTree *tree, Element e)
{
    // 找到这个元素
    BSNode *cur = tree->root;
    BSNode *pre = nullptr;
    BSNode *tmp = nullptr;  // 删除节点后要保留的子树
    while (cur) {
        if (e > cur->data)
        {
            pre = cur;
            cur = cur->right;
        }
        else if (e < cur->data)
        {
            pre = cur;
            cur = cur->left;
        }
        else
            break;
    }
    // 判断度为几
    /*
     * 左边为空，则度只有可能是为 0 或 1
     * */
    if (cur->left == nullptr)
    {
        tmp = cur->right;
    }
    else if (cur->right == nullptr)
    {
        tmp = cur->left;
    }
    else{   // 度为2的节点,从cur节点中找后继，则找后继中最小值
        deleteNode(cur);
        tree->count--;
        return;
    }
    // 判断被删除的点是左孩子还是右孩子，然后将要保留的子树接上去
    if (cur->data < pre->data) {    //左孩子
        pre->left = tmp;
    } else {
        pre->right = tmp;
    }
    // 删除该节点
    delete cur;
    tree->count--;
}

static BSNode *insertBSNode(BSTree *tree, BSNode *node, Element e)
{
    // 归
    if (!node)
    {
        tree->count++;
        return createBSNode(e);
    }
    // 递
    if (e < node->data)
        node->left = insertBSNode(tree, node->left, e);
    else if (e > node->data)
        node->right = insertBSNode(tree, node->right, e);
    return node;
}
int insertBSTreeNodeRecur(BSTree *tree, Element e) {
    if (tree)
    {
        tree->root = insertBSNode(tree, tree->root, e);
        return 0;
    }
    return -1;
}

// 树的高度 ： max(左子树的高度，右子树的高度) + 1
static int heightBSNode(BSNode *node)
{
    if (!node)
        return 0;
    int leftHeight = heightBSNode(node->left);
    int rightHeight = heightBSNode(node->right);
    if (leftHeight > rightHeight)
        return ++leftHeight;
    else
        return ++rightHeight;
}
int heightBSTreeRecur(BSTree *tree) {
    return heightBSNode(tree->root);
}

static BSNode *searchMiniNode(BSNode *node)
{
    while (node && node->left)
        node = node->left;
    return node;
}
static BSNode *deleteBSNodeRecur(BSTree *tree, BSNode *node, Element e)
{
    if (!node)
        return nullptr;
    if (e < node->data)
        node->left = deleteBSNodeRecur(tree, node->left, e);
    else if (e > node->data)
        node->right = deleteBSNodeRecur(tree, node->right, e);
    else {  // 找到了node
        BSNode *tmp;    // 要返回的剩余节点
        if (node->left == nullptr)
        {
            tmp = node->right;
            delete node;
            tree->count--;
            return tmp;
        }
        if (node->right == nullptr)
        {
            tmp = node->left;
            delete node;
            tree->count--;
            return tmp;
        }
        // 度为2，删除度为二的节点，变成找到后继节点(右边最小值)
        // 将后继节点的值拷贝给度为二的点，然后删除后继节点
        tmp = searchMiniNode(node->right);
        node->data = tmp->data;
        node->right = deleteBSNodeRecur(tree,node->right,tmp->data);
    }
    return node;
}
void deleteBSTreeNodeRecur(BSTree *tree, Element e) {
    if (tree) {
        deleteBSNodeRecur(tree, tree->root, e);
    }
}

