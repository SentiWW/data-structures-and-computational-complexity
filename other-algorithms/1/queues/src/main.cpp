#include "stdio.h"
#include "table-queue.h"

int main(void) {
    TableQueue* table_queue = new TableQueue(5);
    table_queue->enqueue(10);
    table_queue->enqueue(20);
    table_queue->enqueue(30);
    table_queue->enqueue(40);
    table_queue->enqueue(50);
    table_queue->enqueue(60);
    table_queue->display();
    table_queue->dequeue();
    table_queue->dequeue();
    table_queue->display();
    return 0;
}