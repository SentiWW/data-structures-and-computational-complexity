#include "two-way-list.h"
#include "two-way-list-node.h"
#include "stdio.h"

TwoWayList::TwoWayList(void) {
    head = nullptr;
    tail = nullptr;
}

TwoWayList::~TwoWayList() {
    
}

void TwoWayList::add(int value) {
    TwoWayListNode* node = new TwoWayListNode(value);

    // If list is empty
    // set element as head
    if (head == nullptr) {
        head = node;
        tail = node;
        return;
    }

    node->previous = tail;
    tail->next = node;
    tail = node;
}

void TwoWayList::remove(int value) {
    TwoWayListNode* current = head;

    while (current != nullptr) {
        if (current->value == value) {
            break;
        }

        current = current->next;
    }

    if (current == nullptr) {
        return;
    }

    TwoWayListNode* next = current->next;
    TwoWayListNode* previous = current->previous;

    if (next == nullptr && previous == nullptr) {
        head = nullptr;
        tail = nullptr;
        delete current;
        return;
    }

    if (next == nullptr) {
        previous->next = nullptr;
        tail = previous;
        delete current;
        return;
    }

    if (previous == nullptr) {
        next->previous = nullptr;
        head = next;
        delete current;
        return;
    }

    next->previous = previous;
    previous->next = next;
    delete current;
}

int* TwoWayList::find(int value) {
    int* found = nullptr;
    TwoWayListNode* current = head;

    while (current != nullptr) {
        if (current->value == value) {
            found = &current->value;
            break;
        }

        current = current->next;
    }

    return found;
}

void TwoWayList::display(void) {
    TwoWayListNode* current = head;

    while (current != nullptr) {
        printf("%d ", current->value);
        current = current->next;
    }
}