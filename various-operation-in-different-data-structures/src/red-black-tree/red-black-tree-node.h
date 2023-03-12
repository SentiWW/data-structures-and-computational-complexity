#ifndef REDBLACKTREENODE_H
#define REDBLACKTREENODE_H

class RedBlackTreeNode
{
private:
    int value;
    enum Color {RED, BLACK} color;
    RedBlackTreeNode* parent;
    RedBlackTreeNode* left;
    RedBlackTreeNode* right;

public:
    RedBlackTreeNode(int value);
    ~RedBlackTreeNode();
    int get_value();
    Color get_color();
    void set_color(Color color);
    bool is_leaf();
    bool has_left_child();
    bool has_right_child();
    RedBlackTreeNode* get_uncle();
    void rotate_left();
    void rotate_right();
    void replace_node(RedBlackTreeNode* replacement);
    RedBlackTreeNode* get_sibling();
    RedBlackTreeNode* get_parent();
    RedBlackTreeNode* get_left_child();
    RedBlackTreeNode* get_right_child();
    void set_value(int value);
    void set_parent(RedBlackTreeNode* parent);
    void set_left_child(RedBlackTreeNode* left);
    void set_right_child(RedBlackTreeNode* right);
    bool is_left_child();
    bool is_right_child();
};

#endif
