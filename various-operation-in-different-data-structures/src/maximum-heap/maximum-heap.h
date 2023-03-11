#ifndef MAXIMUMHEAP_H
#define MAXIMUMHEAP_H

class MaximumHeap
{
private:
    int* heap;
    int capacity;

    int get_parent_index(int child_index);
    int get_left_child_index(int parent_index);
    int get_right_child_index(int parent_index);
    void resize(int new_capacity);
    void heapify_up(int index);
    void heapify_down(int index);

public:
    MaximumHeap(void);
    ~MaximumHeap();
    void add(int value);
    void remove(int value);
    int* find(int value);
    void display(void);
    void display_as_tree(void);
};

#endif