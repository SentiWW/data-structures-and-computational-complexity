#ifndef REDBLACKTREENODE_H
#define REDBLACKTREENODE_H

#include "red-black-tree-colors.h"

class RedBlackTreeNode
{
public:
    int value;
    Color color;
    RedBlackTreeNode* parent;
    RedBlackTreeNode* left;
    RedBlackTreeNode* right;

    RedBlackTreeNode(int value);
    ~RedBlackTreeNode();
};

#endif