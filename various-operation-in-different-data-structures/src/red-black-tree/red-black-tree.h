#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "red-black-tree-node.h"

class RedBlackTree
{
private:
    RedBlackTreeNode* head;

    RedBlackTreeNode* get_min_node(RedBlackTreeNode* node);
    RedBlackTreeNode* get_max_node(RedBlackTreeNode* node);
    RedBlackTreeNode* get_successor(RedBlackTreeNode* node);
    RedBlackTreeNode* get_predecessor(RedBlackTreeNode* node);
    void rotate_left(RedBlackTreeNode* node);
    void rotate_right(RedBlackTreeNode* node);
    void fix_insertion(RedBlackTreeNode* node);
    void fix_deletion(RedBlackTreeNode* node);
    void transplant(RedBlackTreeNode* u, RedBlackTreeNode* v);

public:
    RedBlackTree();
    ~RedBlackTree();
    void add(int value);
    void remove(int value);
    int* find(int value);
    void display();
    void clear();
};

#endif