#include "stdio.h"
#include "table-queue.h"

TableQueue::TableQueue(int capacity) {
    count = 0;
    front = rear = -1;
    size = capacity;
    array = new int[size];
}

bool TableQueue::is_empty() {
    return front == -1 && rear == -1;
}

bool TableQueue::is_full() {
    return rear == size - 1;
}

void TableQueue::enqueue(int val) {
    if (is_full()) {
        printf("Queue is full.");
        return;
    }

    if (is_empty()) {
        front = rear = 0;
    } else {
        rear++;
    }

    count++;
    array[rear] = val;
}

int TableQueue::dequeue() {
    if (is_empty()) {
        printf("Queue is empty.");
        return -1;
    }

    int value = array[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }

    count--;
    return value;
}

void TableQueue::display() {
    if (is_empty()) {
        printf("Queue is empty.");
        return;
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", array[i]);
    }
}