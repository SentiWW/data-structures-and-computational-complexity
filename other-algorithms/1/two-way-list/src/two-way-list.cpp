#include "two-way-list.h"
#include <stdio.h>

TwoWayList::TwoWayList(void) {
    head = nullptr;
    tail = nullptr;
}

void TwoWayList::push_front(TwoWayListNode* node) {
    if (head == nullptr) {
        head = node;
        tail = node;
    } else {
        node->set_next(head);
        head->set_previous(node);
        head = node;
    }
}

void TwoWayList::push_back(TwoWayListNode* node) {
    if (tail == nullptr) {
        head = node;
        tail = node;
    } else {
        node->set_previous(tail);
        tail->set_next(node);
        tail = node;
    }
}

bool TwoWayList::insert(TwoWayListNode* node, int index) { 
    if (index < 0) {
        return false;
    }

    if (head == nullptr) {
        if (index != 0) {
            return false;
        }
        head = node;
        tail = node;
        return true;
    }

    if (index == 0) {
        push_front(node);
        return true;
    }

    TwoWayListNode* current = head;
    int i = 0;
    while (current != nullptr && i < index) {
        current = current->get_next();
        i++;
    }

    if (current == nullptr) {
        return false;
    }

    TwoWayListNode* previous = current->get_previous();
    node->set_next(current);
    node->set_previous(previous);
    previous->set_next(node);
    current->set_previous(node);
    return true;
}

void TwoWayList::display_list(void) {
    TwoWayListNode* current = head;

    while (current != nullptr) {
        printf("%d ", current->value);
        current = current->get_next();
    }
    
    printf("\n");
}

bool TwoWayList::remove_node(int index) {
    if (index < 0 || head == nullptr) {
        return false;
    }

    if (index == 0) {
        TwoWayListNode* next = head->get_next();
        if (next == nullptr) {
            tail = nullptr;
        } else {
            next->set_previous(nullptr);
        }
        delete head;
        head = next;
        return true;
    }

    TwoWayListNode* current = head;
    int i = 0;
    while (current != nullptr && i < index) {
        current = current->get_next();
        i++;
    }

    if (current == nullptr) {
        return false;
    }

    TwoWayListNode* previous = current->get_previous();
    TwoWayListNode* next = current->get_next();
    if (next == nullptr) {
        tail = previous;
    } else {
        next->set_previous(previous);
    }
    previous->set_next(next);
    delete current;
    return true;
}

TwoWayListNode* TwoWayList::find(int value) {
    TwoWayListNode* current = head;

    while (current != nullptr) {
        if (current->value == value) {
            return current;
        }
        
        current = current->get_next();
    }

    return nullptr;
}
