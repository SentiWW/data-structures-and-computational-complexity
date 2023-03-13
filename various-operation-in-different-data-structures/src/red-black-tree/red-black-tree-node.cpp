#include "red-black-tree-node.h"
#include "red-black-tree-colors.h"

RedBlackTreeNode::RedBlackTreeNode(int value)
{
    this->value = value;
    color = RED;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

RedBlackTreeNode::~RedBlackTreeNode()
{

}