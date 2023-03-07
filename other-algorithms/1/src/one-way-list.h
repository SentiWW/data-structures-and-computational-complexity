#ifndef ONEWAYLIST_H
#define ONEWAYLIST_H

#include "one-way-list-node.h"

class OneWayList {
public:
    OneWayListNode* head;
    OneWayList();
    void push_front(OneWayListNode* node);
    void push_back(OneWayListNode* node);
    bool insert(OneWayListNode* node, int index);
    void display_list();
    bool remove_node(int index);
    OneWayListNode* find(int value);
};

#endif