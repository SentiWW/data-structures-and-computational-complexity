#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "red-black-tree-node.h"

class RedBlackTree
{
private:
    RedBlackTreeNode* head;

public:
    RedBlackTree();
    ~RedBlackTree();
    RedBlackTreeNode* find(int value);
    RedBlackTreeNode* get_min_node(RedBlackTreeNode* node);
    RedBlackTreeNode* get_max_node(RedBlackTreeNode* node);
    RedBlackTreeNode* get_successor(RedBlackTreeNode* node);
    RedBlackTreeNode* get_predecessor(RedBlackTreeNode* node);
    void insert(int value);
    void remove(int value);
    bool contains(int value);
    int size();
    void clear();
    void print_tree();
};

#endif
