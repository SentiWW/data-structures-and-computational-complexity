#include "red-black-tree.h"
#include "iostream"

RedBlackTree::RedBlackTree() {
    head = nullptr;
}

RedBlackTree::~RedBlackTree() {
    clear();
}

RedBlackTreeNode* RedBlackTree::find(int value) {
    RedBlackTreeNode* current_node = head;

    while (current_node != nullptr) {
        if (current_node->get_value() == value) {
            return current_node;
        } else if (current_node->get_value() > value) {
            current_node = current_node->get_left_child();
        } else {
            current_node = current_node->get_right_child();
        }
    }

    return nullptr;
}

RedBlackTreeNode* RedBlackTree::get_min_node(RedBlackTreeNode* node)
{
    RedBlackTreeNode* current_node = node;

    while (current_node->has_left_child()) {
        current_node = current_node->get_left_child();
    }

    return current_node;
}

RedBlackTreeNode* RedBlackTree::get_max_node(RedBlackTreeNode* node)
{
    RedBlackTreeNode* current_node = node;

    while (current_node->has_right_child()) {
        current_node = current_node->get_right_child();
    }

    return current_node;
}

RedBlackTreeNode* RedBlackTree::get_successor(RedBlackTreeNode* node)
{
    if (node->has_right_child()) {
        return get_min_node(node->get_right_child());
    } else {
        RedBlackTreeNode* current_node = node;
        RedBlackTreeNode* parent_node = current_node->get_parent();

        while (parent_node != nullptr && current_node == parent_node->get_right_child()) {
            current_node = parent_node;
            parent_node = current_node->get_parent();
        }

        return parent_node;
    }
}

RedBlackTreeNode* RedBlackTree::get_predecessor(RedBlackTreeNode* node)
{
    if (node->has_left_child()) {
        return get_max_node(node->get_left_child());
    }
    else {
        RedBlackTreeNode* current_node = node;
        RedBlackTreeNode* parent_node = current_node->get_parent();

        while (parent_node != nullptr && current_node == parent_node->get_left_child()) {
            current_node = parent_node;
            parent_node = current_node->get_parent();
        }

        return parent_node;
    }
}

void RedBlackTree::insert(int value)
{
    // TODO: Implement insertion algorithm
}

void RedBlackTree::remove(int value)
{
    // TODO: Implement removal algorithm
}

bool RedBlackTree::contains(int value)
{
    return find(value) != nullptr;
}

int RedBlackTree::size()
{
    // TODO: Implement size calculation algorithm
    return 0;
}

void RedBlackTree::clear()
{
    // TODO: Implement tree deletion algorithm
}

void RedBlackTree::print_tree()
{
    // TODO: Implement tree printing algorithm
}
