#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray
{
private:
    int* array;
    int capacity;
    void resize(int new_capacity);

public:
    DynamicArray(void);
    ~DynamicArray();
    void add(int value);
    void remove(int value);
    int* find(int value);
    void display();
};

#endif