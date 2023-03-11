#ifndef TWOWAYLISTNODE_H
#define TWOWAYLISTNODE_H

class TwoWayListNode
{
public:
    int value;
    TwoWayListNode* next;
    TwoWayListNode* previous;

    TwoWayListNode(int value);
    ~TwoWayListNode();
};

#endif