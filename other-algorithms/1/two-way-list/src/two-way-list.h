#ifndef TWOWAYLIST_H
#define TWOWAYLIST_H

#include "two-way-list-node.h"

class TwoWayList {
public:
    TwoWayListNode* head;
    TwoWayListNode* tail;

    TwoWayList(void);

    void push_front(TwoWayListNode* node);
    void push_back(TwoWayListNode* node);
    bool insert(TwoWayListNode* node, int index);
    void display_list(void);
    bool remove_node(int index);
    TwoWayListNode* find(int value);
};

#endif