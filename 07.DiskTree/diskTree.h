//
// Created by 25328 on 23/4/13.
//

#ifndef DATASTRUCTURE_DISKTREE_H
#define DATASTRUCTURE_DISKTREE_H
/*  B树的阶3，说明最大有3颗子树，那么节点最大键值2
 *  在插入节点时，当键值为3时，才会触发分离，申请的时候多申请一个
 * */
#define MaxOrder 3      // m树
typedef int KeyType;    // B树节点键值类型
// B树的节点结构
typedef struct BTNode {
    KeyType key[MaxOrder + 1];
    struct BTNode *ptr[MaxOrder + 1];
    struct BTNode *parent;
    int keyNum;
}BTNode;
// B树结构
typedef struct {
    BTNode *root;
    int count;
}DiskBTree;

#endif //DATASTRUCTURE_DISKTREE_H
