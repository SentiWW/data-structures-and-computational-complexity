#ifndef TABLEQUEUE_H
#define TABLEQUEUE_H

class TableQueue {
private:
    int front, rear, size, count;
    int *array;

public:
    TableQueue(int capacity);
    bool is_empty();
    bool is_full();
    void enqueue(int value);
    int dequeue();
    void display();
};

#endif
