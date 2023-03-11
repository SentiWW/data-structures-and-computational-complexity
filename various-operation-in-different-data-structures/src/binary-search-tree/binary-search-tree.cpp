#include "binary-search-tree.h"
#include "binary-search-tree-node.h"
#include "iostream"
#include "cmath"

BinarySearchTree::BinarySearchTree() {
    head = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
    // Delete all nodes in the tree
    destroy_tree(head);
}

void BinarySearchTree::add(int value) {
    // Add a node using helper
    head = insert_node(head, value);
}

void BinarySearchTree::remove(int value) {
    // Delete the node using helper
    head = delete_node(head, value);
}

int* BinarySearchTree::find(int value) {
    // Find the node using helper
    BinarySearchTreeNode* node = search_tree(head, value);

    // If node was found return
    // a pointer to it's value
    // else return a nullptr
    if (node != nullptr) {
        return &node->value;
    }
    else {
        return nullptr;
    }
}

void BinarySearchTree::display() {
    inorder_traversal(head);
    std::cout << std::endl;
}

BinarySearchTreeNode* BinarySearchTree::insert_node(BinarySearchTreeNode* node, int value) {
    // If node doesn't exist create
    // a node in it's place,
    // do a binary search on the
    // value being added
    if (node == nullptr) {
        node = new BinarySearchTreeNode(value);
    }
    else if (value < node->value) {
        node->left = insert_node(node->left, value);
    }
    else if (value > node->value) {
        node->right = insert_node(node->right, value);
    }

    return node;
}

BinarySearchTreeNode* BinarySearchTree::delete_node(BinarySearchTreeNode* node, int value) {
    // If node doesn't exist
    // return it
    if (node == nullptr) {
        return nullptr;
    }

    // If the value being searched for
    // is less than the value of current
    // node, recurse to the left child, else
    // recurse to the right child
    // if it's equal to the value, delete it
    if (value < node->value) {
        node->left = delete_node(node->left, value);
    }
    else if (value > node->value) {
        node->right = delete_node(node->right, value);
    }
    else {
        // If the current node doesn't have
        // a left child, replace it with the right child
        if (node->left == nullptr) {
            BinarySearchTreeNode* temp = node->right;
            delete node;
            return temp;
        }
        // If the current node doesn't have
        // a right child, replace it with the left child
        else if (node->right == nullptr) {
            BinarySearchTreeNode* temp = node->left;
            delete node;
            return temp;
        }
        
        // If the current node has both 
        // a left and a right child,
        // replace it with the minimum value 
        // in its right subtree
        BinarySearchTreeNode* temp = find_min(node->right);
        node->value = temp->value;
        node->right = delete_node(node->right, temp->value);
    }

    return node;
}

BinarySearchTreeNode* BinarySearchTree::search_tree(BinarySearchTreeNode* node, int value) {
    // If node doesn't exist
    // or is the node with the searched
    // value, return it
    if (node == nullptr || node->value == value) {
        return node;
    }

    // If the value being searched for
    // is less than the value of current
    // node, recurse to the left child, else
    // recurse to the right child
    if (value < node->value) {
        return search_tree(node->left, value);
    }
    else {
        return search_tree(node->right, value);
    }
}

BinarySearchTreeNode* BinarySearchTree::find_min(BinarySearchTreeNode* node) {
    BinarySearchTreeNode* current = node;

    // Get the leftmost existing node
    // this will be the min of the tree
    while (current->left != nullptr) {
        current = current->left;
    }

    return current;
}

void BinarySearchTree::inorder_traversal(BinarySearchTreeNode* node) {
    // If current node exists
    // recurse into its left child
    // write the current node
    // and recure into its right child
    // this will write the tree
    // in ascending order
    if (node != nullptr) {
        inorder_traversal(node->left);
        std::cout << node->value << " ";
        inorder_traversal(node->right);
    }
}

void BinarySearchTree::destroy_tree(BinarySearchTreeNode* node) {
    // If current node exists
    // recurse into its children
    // and delete it
    if (node != nullptr) {
        destroy_tree(node->left);
        destroy_tree(node->right);
        delete node;
    }
}