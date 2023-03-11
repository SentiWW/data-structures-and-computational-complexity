#include "maximum-heap.h"
#include "iostream"
#include "cmath"

MaximumHeap::MaximumHeap() {
    capacity = 0;
    heap = nullptr;
}

MaximumHeap::~MaximumHeap() {
    delete[] heap;
}

void MaximumHeap::add(int value) {
    if (capacity == 0)
    {
        heap = new int[1];
        heap[0] = value;
        capacity++;
        return;
    }

    capacity++;
    resize(capacity);
    heap[capacity - 1] = value;
    heapify_up(capacity - 1);
}

void MaximumHeap::remove(int value) {
    if (capacity == 0) {
        return;
    }
    int index = -1;
    for (int i = 0; i < capacity; i++) {
        if (heap[i] == value) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return;
    }
    heap[index] = heap[capacity-1];
    capacity--;
    if (index == 0 || heap[index] < heap[get_parent_index(index)]) {
        heapify_down(index);
    } else {
        heapify_up(index);
    }
    if (capacity <= capacity / 4) {
        resize(capacity / 2);
    }
}

int* MaximumHeap::find(int value) {
    for (int i = 0; i < capacity; i++) {
        if (heap[i] == value) {
            return &heap[i];
        }
    }
    return nullptr;
}

void MaximumHeap::display() {
    for (int i = 0; i < capacity; i++)
    {
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}

int MaximumHeap::get_parent_index(int child_index) {
    return (child_index - 1) / 2;
}

int MaximumHeap::get_left_child_index(int parent_index) {
    return 2 * parent_index + 1;
}

int MaximumHeap::get_right_child_index(int parent_index) {
    return 2 * parent_index + 2;
}

void MaximumHeap::resize(int new_capacity) {
    int* new_heap = new int[new_capacity];
    for (int i = 0; i < new_capacity; i++) {
        if (i < capacity) {
            new_heap[i] = heap[i];
        } else {
            new_heap[i] = 0;
        }
    }
    delete[] heap;
    heap = new_heap;
    capacity = new_capacity;
}

void MaximumHeap::heapify_down(int index) {
    int left_index = get_left_child_index(index);
    int right_index = get_right_child_index(index);
    int largest_index = index;

    if (left_index < capacity && heap[left_index] > heap[largest_index]) {
        largest_index = left_index;
    }

    if (right_index < capacity && heap[right_index] > heap[largest_index]) {
        largest_index = right_index;
    }

    if (largest_index != index) {
        std::swap(heap[index], heap[largest_index]);

        heapify_down(largest_index);
    }
}

void MaximumHeap::heapify_up(int index) {
    int parent_index = get_parent_index(index);
    
    while (index > 0 && heap[index] > heap[parent_index]) {
        std::swap(heap[index], heap[parent_index]);

        index = parent_index;
        parent_index = get_parent_index(index);
    }
}

void MaximumHeap::display_as_tree(void) {
    int height = log2(capacity) + 1;
    int index = 0;

    for (int i = 1; i <= height; i++) {
        for (int j = 0; j < pow(2, i - 1); j++) {
            if (index >= capacity) {
                return;
            }

            std::cout << heap[index] << " ";
            index++;
        }
        std::cout << std::endl;
    }
}
