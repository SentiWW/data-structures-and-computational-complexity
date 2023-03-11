#ifndef BINARYSEARCHTREENODE_H
#define BINARYSEARCHTREENODE_H

class BinarySearchTreeNode
{
public:
    BinarySearchTreeNode* left;
    BinarySearchTreeNode* right;
    int value;

    BinarySearchTreeNode(int value);
    ~BinarySearchTreeNode();
};

#endif