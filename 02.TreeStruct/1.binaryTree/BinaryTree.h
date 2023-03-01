//
// Created by 25328 on 2023/2/5.
//

#ifndef DATASTRUCTURE_BINARYTREE_H
#define DATASTRUCTURE_BINARYTREE_H

using Element = int;
//树的节点结构
typedef struct treeNode {
    Element data;
    struct treeNode* left;
    struct treeNode* right;
    explicit treeNode(Element data, treeNode *left = nullptr, treeNode *right  = nullptr)
        : data(data)
        , left(left)
        ,right(right)
    {};
    explicit treeNode()= default;;
}TreeNode;

//二叉树的描述信息结构
typedef struct {
    TreeNode *root; //二叉树的根节点
    int count;      //二叉树的节点个数
}BinaryTree;

BinaryTree *createBinaryTree(TreeNode *root);
void releaseBinaryTree(BinaryTree *tree);

TreeNode *createTreeNode(Element e);
void insertBinaryTree(BinaryTree *tree, TreeNode *parent, TreeNode *leftChild, TreeNode *rightChild);

void floorOrderBTreeRecur(BinaryTree *tree);

void preOrderBTreeRecur(TreeNode *node);
void midOrderBTreeRecur(TreeNode *node);
void lastOrderBTreeRecur(TreeNode *node);

// 非递归遍历
void preOrderBTreeNoRecur(BinaryTree *tree);
void midOrderBTreeNoRecur(BinaryTree *tree);
void lastOrderBTreeNoRecur(BinaryTree *tree);
#endif //DATASTRUCTURE_BINARYTREE_H
