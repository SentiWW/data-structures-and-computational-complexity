#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "binary-search-tree-node.h"

class BinarySearchTree
{
private:
    BinarySearchTreeNode* head;

    BinarySearchTreeNode* insert_node(BinarySearchTreeNode* node, int value);
    BinarySearchTreeNode* delete_node(BinarySearchTreeNode* node, int value);
    BinarySearchTreeNode* search_tree(BinarySearchTreeNode* node, int value);
    BinarySearchTreeNode* find_min(BinarySearchTreeNode* node);
    void inorder_traversal(BinarySearchTreeNode* node);
    void destroy_tree(BinarySearchTreeNode* node);

public:
    BinarySearchTree(void);
    ~BinarySearchTree();
    void add(int value);
    void remove(int value);
    int* find(int value);
    void display();
};

#endif