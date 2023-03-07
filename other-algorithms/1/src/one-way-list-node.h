#ifndef ONEWAYLISTNODE_H
#define ONEWAYLISTNODE_H

class OneWayListNode {
public:
    OneWayListNode* next;
    OneWayListNode(int value);
    OneWayListNode* get_next();
    int value;

    void set_next(OneWayListNode* node);
};

#endif