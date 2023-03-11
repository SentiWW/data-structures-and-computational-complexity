#include "dynamic-array.h"
#include "stdio.h"

DynamicArray::DynamicArray(void) {
    capacity = 0;
    array = nullptr;
}

DynamicArray::~DynamicArray() {
    // Delete array when DynamicArray
    // gets deleted
    delete[] array;
}

void DynamicArray::resize(int new_capacity) {
    int new_array[new_capacity];
    int resize_capacity = new_capacity < capacity 
        ? new_capacity
        : capacity;

    // Copy old array to new array
    // if old array exists
    if (array != nullptr) {
        for (int i = 0; i < resize_capacity; i++) {
            new_array[i] = array[i];
        }
    }

    array = new_array;
    capacity = new_capacity;
}

void DynamicArray::add(int value) {
    // Resize array to make space
    // for new element
    resize(capacity + 1);

    // Add new element at last position
    array[capacity - 1] = value;
}

void DynamicArray::remove(int value) {
    int element_index = -1;

    // Finding element index
    for (int i = 0; i < capacity; i++) {
        if (array[i] == value)
        {
            element_index = i;
            break;
        }
    }

    // Element not found
    if (element_index == -1) {
        return;
    }

    // Move all elements one position
    // down in the array
    if (element_index != capacity - 1) {
        for (int i = element_index + 1; i < capacity; i++) {
            array[i - 1] = array[i];
        }
    }

    // Resize array
    resize(capacity - 1);
}

int* DynamicArray::find(int value) {
    int* found = nullptr;

    for (int i = 0; i < capacity; i++) {
        if (array[i] == value) {
            found = &array[i];
        }
    }
    
    return found;
}

void DynamicArray::display() {
    for (int i = 0; i < capacity; i++) {
        printf("%d ", array[i]);
    }
}
