#include "red-black-tree.h"
#include "iostream"

RedBlackTreeNode* RedBlackTree::get_min_node(RedBlackTreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }

    return node;
}    

RedBlackTreeNode* RedBlackTree::get_max_node(RedBlackTreeNode* node) {
    while (node->right != nullptr) {
        node = node->right;
    }

    return node;
}

RedBlackTreeNode* RedBlackTree::get_successor(RedBlackTreeNode* node) {
    if (node->right != nullptr) {
        return get_min_node(node->right);
    }

    RedBlackTreeNode* parent = node->parent;

    while (parent != nullptr && node == parent->right) {
        node = parent;
        parent = parent->parent;
    }

    return parent;
}

RedBlackTreeNode* RedBlackTree::get_predecessor(RedBlackTreeNode* node) {
    if (node->left != nullptr) {
        return get_max_node(node->left);
    }

    RedBlackTreeNode* parent = node->parent;

    while (parent != nullptr && node == parent->left) {
        node = parent;
        parent = parent->parent;
    }

    return parent;
}

void RedBlackTree::rotate_left(RedBlackTreeNode* node) {
    RedBlackTreeNode* new_node = node->right;

    node->right = new_node->left;
    if (new_node->left != nullptr){
        new_node->left->parent = node;
    }

    new_node->parent = node->parent;
    if (node->parent == nullptr) {
        head = new_node;
    }
    else if (node == node->parent->left) {
        node->parent->left = new_node;
    }
    else {
        node->parent->right = new_node;
    }

    new_node->left = node;
    node->parent = new_node;
}

void RedBlackTree::rotate_right(RedBlackTreeNode* node) {
    RedBlackTreeNode* new_node = node->left;

    node->left = new_node->right;
    if (new_node->right != nullptr) {
        new_node->right->parent = node;
    }

    new_node->parent = node->parent;
    if (node->parent == nullptr) {
        head = new_node;
    }
    else if (node == node->parent->left) {
        node->parent->left = new_node;
    }
    else {
        node->parent->right = new_node;
    }

    new_node->right = node;
    node->parent = new_node;
}

void RedBlackTree::fix_insertion(RedBlackTreeNode* node) {
    RedBlackTreeNode* current = node;

    while (current->parent != nullptr && current->parent->color == RED) {
        if (current->parent == current->parent->parent->left) {
            RedBlackTreeNode* uncle = current->parent->parent->right;

            if (uncle != nullptr && uncle->color == RED) {
                current->parent->color = BLACK;
                uncle->color = BLACK;
                current->parent->parent->color = RED;
                current = current->parent->parent;
            }
            else {
                if (current == current->parent->right) {
                    current = current->parent;
                    rotate_left(current);
                }

                current->parent->color = BLACK;
                current->parent->parent->color = RED;
                rotate_right(current->parent->parent);
            }
        }
        else {
            RedBlackTreeNode* uncle = current->parent->parent->left;

            if (uncle != nullptr && uncle->color == RED) {
                current->parent->color = BLACK;
                current->color = BLACK;
                current->parent->parent->color = RED;
                current = current->parent->parent;
            }

            else {
                if (current == current->parent->left) {
                    current = current->parent;
                    rotate_right(current);
                }

                current->parent->color = BLACK;
                current->parent->parent->color = RED;
                rotate_left(current->parent->parent);
            }
        }
    }
    
    head->color = BLACK;
}

// TODO: Fix this
void RedBlackTree::fix_deletion(RedBlackTreeNode* node)
{
    RedBlackTreeNode* current = node;

    while (current != head && current->color == BLACK) {
        if (current == current->parent->left) {
            RedBlackTreeNode* sibling = current->parent->right;

            if (sibling->color == RED) {
                sibling->color = BLACK;
                current->parent->color = RED;
                rotate_left(current->parent);
                sibling = current->parent->right;
            }

            if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
                sibling->color = RED;
                current = current->parent;
            }
            else {
                if (sibling->right->color == BLACK) {
                    sibling->left->color = BLACK;
                    sibling->color = RED;
                    rotate_right(sibling);
                    sibling = current->parent->right;
                }

                sibling->color = current->parent->color;
                current->parent->color = BLACK;
                sibling->right->color = BLACK;
                rotate_left(current->parent);
                current = head;
            }
        }
        else {
            RedBlackTreeNode* sibling = current->parent->left;

            if (sibling->color == RED) {
                sibling->color = BLACK;
                current->parent->color = RED;
                rotate_right(current->parent);
                sibling = current->parent->left;
            }
            
            if (sibling->right->color == BLACK && sibling->left->color == BLACK) {
                sibling->color = RED;
                current = current->parent;
            }
            else {
                if (sibling->left->color == BLACK) {
                    sibling->right->color = BLACK;
                    sibling->color = RED;
                    rotate_left(sibling);
                    sibling = current->parent->left;
                }

                sibling->color = current->parent->color;
                current->parent->color = BLACK;
                sibling->left->color = BLACK;
                rotate_right(current->parent);
                current = head;
            }
        }
    }

    current->color = BLACK;
}

void RedBlackTree::transplant(RedBlackTreeNode* u, RedBlackTreeNode* v)
{
    if (u->parent == nullptr) {
        head = v;
    }
    else if (u == u->parent->left) {
        u->parent->left = v;
    }
    else {
        u->parent->right = v;
    }

    if (v != nullptr) {
        v->parent = u->parent;
    }
}

RedBlackTree::RedBlackTree() {
    head = nullptr;
}

RedBlackTree::~RedBlackTree() {
    clear();
}

void RedBlackTree::add(int value) {
    RedBlackTreeNode* node = new RedBlackTreeNode(value);
    RedBlackTreeNode* current = head;
    RedBlackTreeNode* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (value < current->value) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    node->parent = parent;
    if (parent == nullptr) {
        head = node;
    }
    else if (value < parent->value) {
        parent->left = node;
    }
    else {
        parent->right = node;
    }

    node->left = nullptr;
    node->right = nullptr;
    node->color = RED;
    fix_insertion(node);
}

// TODO: Fix this
void RedBlackTree::remove(int value) {
    RedBlackTreeNode* node = head;

    while (node != nullptr) {
        if (value == node->value) {
            break;
        }
        else if (value < node->value) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }

    if (node == nullptr) {
        return;
    }

    Color original_color = node->color;
    RedBlackTreeNode* x;

    if (node->left == nullptr) {
        x = node->right;
        transplant(node, node->right);
    }
    else if (node->right == nullptr) {
        x = node->left;
        transplant(node, node->left);
    }
    else {
        RedBlackTreeNode* min_node = get_min_node(node->right);
        original_color = min_node->color;
        x = min_node->right;

        if (min_node->parent == node) {
            x->parent = min_node;
        }
        else {
            transplant(min_node, min_node->right);
            min_node->right = node->right;
            min_node->right->parent = min_node;
        }

        transplant(node, min_node);
        min_node->left = node->left;
        min_node->left->parent = min_node;
        min_node->color = node->color;
    }

    delete node;

    if (original_color == BLACK) {
        fix_deletion(x);
    }
}

int* RedBlackTree::find(int value) {
    RedBlackTreeNode* node = head;

    while (node != nullptr) {
        if (value == node->value) {
            return &node->value;
        }
        else if (value < node->value) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }

    return nullptr;
}

void display_helper(RedBlackTreeNode* node, int indent) {
    if (node != nullptr) {
        display_helper(node->right, indent + 4);

        for (int i = 0; i < indent; i++) {
            std::cout << " ";
        }

        std::cout << node->value;

        if (node->color == RED) {
            std::cout << " (R)";
        }
        else {
            std::cout << " (B)";
        }

        std::cout << std::endl;
        display_helper(node->left, indent + 4);
    }
}

void RedBlackTree::display() {
    std::cout << "Red Black Tree:" << std::endl;
    if (head != nullptr) {
        display_helper(head, 0);
    }
}

void clear_helper(RedBlackTreeNode* node) {
    if (node != nullptr) {
        clear_helper(node->left);
        clear_helper(node->right);
        delete node;
    }
}

void RedBlackTree::clear() {
    clear_helper(head);
    head = nullptr;
}