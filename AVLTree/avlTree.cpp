//
// Created by 25328 on 2023/2/25.
//
#include <stdio.h>
#include "avlTree.h"
enum Type
{
    LL,
    LR,
    RL,
    RR
};
AVLTree *createAVLTree() {
    AVLTree *tree = new AVLTree;
    return tree;
}
static void deleteNode(AVLTree *tree, AVLNode *node)
{
    if(!node)
        return;
    deleteNode(tree, node->left);
    deleteNode(tree, node->right);
    delete node;
    tree->count--;
}
void releaseAVLTree(AVLTree *tree) {
    if(tree)
        deleteNode(tree,tree->root);
    printf("AVLTree has %d node", tree->count);
    delete tree;
}

void visitAVLNode(AVLNode *node) {
    if (node)
        printf("<%d, %d>  ",node->data,node->height);
}

static void inOrderRecur(AVLNode *node)
{
    if (!node)
        return;
    inOrderRecur(node->left);
    visitAVLNode(node);
    inOrderRecur(node->right);
}
void inOrderAVLTree(AVLTree *tree) {
    if (tree)
        inOrderRecur(tree->root);
}

static int maxNum(int a, int b)
{
    return (a > b) ? a : b;
}
static int h(AVLNode *node)
{
    if(!node)
        return 0;
    else
        return node->height;
}
// 左旋
/*
 *         px
 *         |
 *         x
 *       /  \
 *      lx   y
 *          / \
 *         ly  ry
 * */
static AVLNode *leftRotate(AVLNode *x)
{
    AVLNode *y = x->right;
    x->right = y->left;
    y->left = x;
    // 更新节点的高度
    x->height = maxNum(h(x->left), h(x->right)) + 1;
    y->height = maxNum(h(y->left), h(y->right)) + 1;
    return y;
}
// 右旋
/*
 *          py
 *          |
 *          y
 *         / \
 *        x   ry
 *       / \
 *      lx  rx
 * */
static AVLNode *rightRotate(AVLNode *y)
{
    AVLNode *x = y->left;
    y->left = x->right;
    x->right = y;
    x->height = maxNum(h(x->left), h(x->right)) + 1;
    y->height = maxNum(h(y->left), h(y->right)) + 1;
    return x;
}
static AVLNode *createAVLNode(Element e) {
    AVLNode *node = new AVLNode;
    node->data = e;
    node->height = 1;
    return node;
}
static int sub(AVLNode *node)
{
    if(!node)
        return 0;
    return h(node->left) - h(node->right);
}

//static int check(AVLNode *node) {
//    if(node->left->height > node->right->height) // LX
//        check(node->left);
//    else
//        check(node->right);
//}
static AVLNode *insertAVLNode(AVLTree *tree, AVLNode *node, Element e) {
    if(!tree)
        return nullptr;
    if(!node)
    {
        tree->count++;
        return createAVLNode(e);
    }
    // 1. 递归找到插入 BST
    if(!tree->root)
    {
        tree->root = node;
        tree->count++;
        return tree->root;
    }
    if(e < node->data)
        node->left = insertAVLNode(tree,node->left,e);
    else if(e > node->data)
        node->right = insertAVLNode(tree,node->right,e);
    else {  // 插入的元素已经存在
        return node;
    }
    // 2. 归的过程中，更新归中节点的高度
    node->height = maxNum(h(node->left), h(node->right)) + 1;
    // 3. 判断平衡因子
    int balance = sub(node);
    if(balance > 1) //失衡节点左边重
    {
        // 跟失衡节点的子节点判断下一步是L还是R
        if(e < node->left->data) {      // LR
            // 把LR中 把R进行左旋，转换成 LL 状态
            node->left = leftRotate(node->left);
        }
        return rightRotate(node);   // LL 状态，将x归回
    }
    else if(balance < -1)   // 失衡节点右边重
    {
        if(e < node->right->data) { //RL
            node->right = rightRotate(node->right);
        }
        return leftRotate(node);
    }
    return node;    // 没有失衡，直接归
}
void insertAVLTree(AVLTree *tree, Element e) {
    if(tree) {
        tree->root = insertAVLNode(tree,tree->root,e);
    }
}

/*
 * 从平衡二叉树中删除元素e
 * 1. 按照二叉搜索树的规则，递归找到元素e所在节点
 * 2. 判断这个节点的度
 *      2.1 如果是度为1，用父节点接收存在的子树
 *      2.2 如果是度为0，直接删除（父节点接收空指针）
 *      2.3 如果是度为2，找到这个节点的前驱或者后继，用这个节点的值替代度为2的点，
 *              转换成删除这个前驱（后继）
 * 3. 判断平衡因子
 * */
static AVLNode *deleteAVLNodeRecur(AVLTree *tree, AVLNode *node, Element e) {
    if(!node)
        return nullptr;
    // 1. 找到删除节点
    AVLNode *tmp;
    if(e < node->data)
        node->left = deleteAVLNodeRecur(tree, node->left, e);
    else if(e > node->data)
        node->right = deleteAVLNodeRecur(tree, node->left, e);
    else {  // 找到了
        // 按照二分搜索树的规则，删除
        if(node->left == nullptr || node->right == nullptr) {   // 度为1
            tmp = node->left ? node->left : node->right;
            if(tmp == nullptr) {    // 度为0
                delete node;
                tree->count--;
                return nullptr;
            }
            node->data = tmp->data;
            node->left = tmp->left;
            node->right = tmp->right;
            delete tmp;
            tmp = nullptr;
            tree->count--;
            // 判断平衡
        }
        else {      // 找前驱节点，然后更新这个节点，转换为删除前驱节点
            tmp = node->left;
            while (tmp->right) {
                tmp = tmp->right;
            }
            node->data = tmp->data;
            node->left = deleteAVLNodeRecur(tree,node->left,tmp->data);
        }
    }
    // 2. 更新平衡因子
    node->height = 1 + maxNum(h(node->left), h(node->right));
    int balance = sub(node);
    if (balance > 1) {  // L
        if(/* sub(node->left) < 0*/e > node->left->data) { // LR
            node->left = leftRotate(node->left);
        }
        return rightRotate(node); //LL
    }
    else if (balance < -1) { //R
        if (/* sub(node->right) > 0*/e < node->left->data)   // RL
            node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void deleteAVLNode(AVLTree *tree, Element e) {
    if(tree) {
        tree->root = deleteAVLNodeRecur(tree,tree->root,e);
    }
}
