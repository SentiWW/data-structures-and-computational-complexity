#ifndef TWOWAYLIST_H
#define TWOWAYLIST

#include "two-way-list-node.h"

class TwoWayList
{
public:
    TwoWayListNode* head;
    TwoWayListNode* tail;

    TwoWayList(void);
    ~TwoWayList();
    void add(int value);
    void remove(int value);
    int* find(int value);
    void display();
};

#endif