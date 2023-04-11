//
// Created by 25328 on 23/4/7.
//
#include <cstring>
#include <cstdio>
#include "RBTree.h"
/* 将x进行左旋，将左、右、父节点进行更新
 *      px                              px
 *     /                               /
 *    x                               y
 *   /  \      --(左旋)-->           / \
 *  lx   y                          x  ry
 *     /   \                       /  \
 *    ly   ry                     lx  ly
*/
static void leftRotate(RBTree *tree, RBNode *x) {
        RBNode *y = x->right;   // 找到y节点
        // 移动y的左子树
        x->right = y->left;
        if (y->left) {
            y->left->parent = x;
        }
        // x的父节点重新指向y节点
        y->parent = x->parent;
        if (x->parent) {                // x的父节点存在
            // x是父节点的左节点还是右节点
            if (x->parent->left == x) {
                x->parent->left = y;
            }else {
                x->parent->right = y;
            }
        }else {                        // x为根节点
            tree->root = y;
        }
        // 将x插入y的左子树
        y->left =x;
        x->parent = y;
}

/* 将y进行左旋，将左、右、父节点进行更新
 *           py                               py
 *           /                                /
 *          y                                x
 *         /  \      --(右旋)-->            /  \
 *        x   ry                           lx   y
 *       / \                                   / \
 *      lx  rx                                rx  ry
 * */
static void rightRotate(RBTree *tree, RBNode *y) {
    RBNode *x = y->left;        // 找x
    y->left = x->right;
    if (x->right) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent) {
        if (y->parent->left == y) {
            y->parent->left = x;
        }else {
            y->parent->right = x;
        }
    }else {
        tree->root = x;
    }
    x->right = y;
    y->parent = x;
}

RBTree *createRBTree() {
    RBTree * tree = new RBTree;
    return tree;
}

static void insertFixUp(RBTree *tree, RBNode *node) {
    RBNode *parent, *grandParent, *uncle;
    RBNode *tmp;
    parent = node->parent;                      // 找到父节点
    while (parent && parent->color == RED) {
        grandParent = parent->parent;           // 找到祖父节点（有叔叔节点，必有祖父节点）
        // 找到叔叔节点
        if (parent == grandParent->left) {
            uncle = grandParent->right;
        }else {
            uncle = grandParent->left;
        }
        if (uncle && uncle->color == RED) { // 叔叔节点为红色
            uncle->color = BLACK;
            parent->color = BLACK;
            grandParent->color = RED;
            node = grandParent;
            parent = node->parent;
            continue;
        }
        if (grandParent->left == parent) {
            if (parent->right == node) {
                // LR
                // 1.parent左旋
                leftRotate(tree,parent);
                // 2. 交换cur和parent
                tmp = parent;
                parent = node;
                node = tmp;
            }
            // LL
            rightRotate(tree,grandParent);
            grandParent->color = RED;
            parent->color = BLACK;
        }else {
            if (parent->left == node) {
                // RL
                rightRotate(tree, parent);
                tmp = parent;
                parent = node;
                node = tmp;
            }
            // RR
            leftRotate(tree, grandParent);
            grandParent->color = RED;
            parent->color = BLACK;
        }
    }
    tree->root->color = BLACK;
}

static void insertBSTreeNode(RBTree *tree, RBNode *rbNode) {
    RBNode *cur = tree->root;
    RBNode *pre{};
    while (cur) {
        pre = cur;
        if (cur->key > rbNode->key) {  // key值小于node的key值，左边插入
            cur = cur->left;
        }
        else if (cur->key <= rbNode->key) {
            cur = cur->right;
        }
    }
    // 3. 若是根节点，更新tree，否则接入红黑树
    rbNode->parent = pre;
    if (pre) {
        if (pre->key > rbNode->key) {
            pre->left = rbNode;
        } else {
            pre->right = rbNode;
        }
    } else {
        tree->root = rbNode;
        tree->root->color = BLACK;
        tree->count++;
        return;
    }
    insertFixUp(tree,rbNode);
    tree->count++;
}

static RBNode *createRBNode(KeyType key) {
    RBNode *node = new RBNode;
    node->key = key;
    node->color = RED;
    return node;
}

/* 1. 插入节点，如果父节点是黑色的，那么就不用调整
 * 2. 如果父节点是红色，就出现红红现象
 *      a。叔叔节点是红色
 *          1. 叔叔节点和父节点变黑
 *          2. 祖父节点变红
 *          3. 当前节点为祖父节点 【循环判断】
 *      b.叔叔节点是黑色
 *          1. cur是左孩子，parent是左孩子  LL
 *              1) g右旋，变红色
 *              2) p变黑色
 *          2. cur是右孩子，parent是右孩子  RR
 *              1) g左旋，变红色
 *              2) p变黑色
 *          3. cur是右孩子，parent是左孩子  RL
 *              1) p左旋，cur和parent交换
 *              2) LL操作
 *          4. cur是左孩子，parent是右孩子  LR
 *              1） p右旋，cur和parent交换
 *              2)RR操作
 * */
void insertRBNode(RBTree *tree, KeyType key) {
    if (tree == nullptr || key == NULL)
        return;
    // 1. 创建一个红节点
    RBNode *node = createRBNode(key);
    // 2. 将该节点插入树中
    insertBSTreeNode(tree, node);
}

void printRBTree(RBNode *node, int key, int dir) {
    if (node) {
        if (dir == 0) {
            printf("%d[%c] is root\n",node->key, (node->color == RED ? 'R' : 'B'));

        }else {
            printf("%d[%c] is %d's %s\n",node->key,
                   (node->color == RED ? 'R' : 'B'), key,
                   (dir == 1 ? "right child" : "left child"));
        }
        printRBTree(node->left, node->key, -1);
        printRBTree(node->right, node->key, 1);

    }
}

static void deleteRBNodeRecur(RBTree *tree, RBNode *node) {
    if (node == NULL) return;
    // 后序遍历释放
    deleteRBNodeRecur(tree, node->left);
    deleteRBNodeRecur(tree, node->right);
    delete node;
    tree->count--;
}
void releaseRBTree(RBTree *tree, RBNode *node) {
    deleteRBNodeRecur(tree,node);
    printf("last %d nodes",tree->count);
    delete tree;
}
static void deleteFixup(RBTree *tree, RBNode *x, RBNode *parent) {
    RBNode *w;  // 兄弟节点
    while (tree->root != x && (x==NULL || x->color == BLACK)) {
        // 找兄弟节点
        if (parent->left == x) {    //x是父节点的左孩子
            w = parent->right;      // w是右孩子  R
            if (w->color == RED) {
                // 1. x的兄弟是红色
                w->color = BLACK;
                w->parent->color = RED;
                leftRotate(tree, parent);
                w = parent->right;
            }
            // 兄弟节点都是黑色
            if ((!w->left || w->left->color == BLACK) &&
                (!w->right || w->right->color == BLACK)) {
                // 2. x的兄弟的两个孩子都是黑色
                w->color = RED;
                x = parent;
                parent = x->parent;
            } else {
                if (!w->right || w->right->color == BLACK) {
                    // 3. x的兄弟节点左孩子是红色，右孩子是黑色   RL
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(tree,w);
                    w = parent->right;
                }
                // RR  4.
                w->color = parent->color;
                parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(tree, parent);
                x = tree->root;
                break;
            }
        }else {
            w = parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                parent->color = RED;
                rightRotate(tree, parent);
                w = parent->left;
            }
            if ((!w->left || w->left->color == BLACK) &&
                    (!w->right || w->right->color == BLACK)) {
                // 2.
                w->color = RED;
                x = parent;
                parent = x->parent;
            } else {
                if (!w->left || w->left->color == BLACK) {
                    // case 3
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(tree, w);
                    w = parent->left;
                }
                // case 4
                w->color = parent->color;
                parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(tree, parent);
                break;
            }
        }
    }
    if (tree->root) {
        tree->root->color = BLACK;
    }
}
static void deleteRBNode(RBTree *tree, RBNode *node) {
    RBNode *y;  //真正删除的节点地址
    RBNode *x;  //替换节点
    RBNode *parent;
    if (node->left == NULL || node->right == NULL) {
        y = node;
    } else {    // 拥有左右子树的节点，需要寻找后继节点
        y = node->right;
        while (y->left) {
            y = y->left;
        }
    }
    // 真正删除的节点就找到了，然后开始寻找替换节点
    if (y->left) {
        x = y->left;
    }else {
        x = y->right;
    }
    parent = y->parent;
    if(x) {
        x->parent = parent;
    }
    if(y->parent == NULL) {
        tree->root = x;
    } else if(y->parent->left == y) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    //更新有左右孩子的根节点的值
    if(y != node) {
        node->key = y->key;
    }
    // 如果删除的节点是黑色，那么需要调整
    if (y->color == BLACK) {
        deleteFixup(tree, x, parent);
    }
    delete y;
}

void deleteRBTree(RBTree *tree, KeyType key) {
    RBNode *node = searchRBNode(tree, key);
    if (node) {
        deleteRBNode(tree, node);
        tree->count--;
    }
}

RBNode *searchRBNode(RBTree *tree, KeyType key) {
    RBNode *node = tree->root;
    while (node) {
        if (key < node->key) {
            node = node->left;
        }else if (key > node->key) {
            node = node->right;
        }else {
            return node;
        }
    }
    return nullptr;
}
