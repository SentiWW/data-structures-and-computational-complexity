#include "one-way-list.h"
#include "stdio.h"

OneWayList::OneWayList(void) {
    head = nullptr;
}

void OneWayList::push_front(OneWayListNode* node) {
    if (head == nullptr) {
        head = node;
        return;
    }

    node->set_next(head);
    head = node;
}

void OneWayList::push_back(OneWayListNode* node) {
    if (head == nullptr) {
        head = node;
        return;
    }

    OneWayListNode* last = head;
    while (last->get_next() != nullptr) {
        last = last->get_next();
    }

    last->set_next(node);
}

bool OneWayList::insert(OneWayListNode* node, int index) { 
    OneWayListNode* previous = nullptr;
    OneWayListNode* current = head;

    for (int i = 0; i < index; i++) {
        if (current == nullptr) { 
            return false;
        }

        previous = current;
        current = current->get_next();
    }

    if (previous != nullptr) {
        node->set_next(current);
        previous->set_next(node);
    } else {
        node->set_next(head);
        OneWayList::head = node;
    }

    return true;
}

void OneWayList::display_list(void) {
    OneWayListNode* current = head;

    while (current != nullptr) {
        printf("%d ", current->value);
        current = current->get_next();
    }
    
    printf("\n");
}

bool OneWayList::remove_node(int index) {
    OneWayListNode* previous = nullptr;
    OneWayListNode* current = head;

    for (int i = 0; i < index; i++) {
        if (current == nullptr) { 
            return false;
        }

        previous = current;
        current = current->get_next();
    }

    if (previous != nullptr) { 
        OneWayListNode* next = current->get_next();
        previous->set_next(next);
    } else {
        OneWayList::head = current->get_next();
    }
    
    delete current;
    return true;
}

OneWayListNode* OneWayList::find(int value) {
    OneWayListNode* current = head;

    while (current != nullptr) {
        if (current->value == value) {
            return current;
        }
        
        current = current->get_next();
    }
}