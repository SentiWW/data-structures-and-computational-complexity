#ifndef TWOWAYLISTNODE_H
#define TWOWAYLISTNODE_H

class TwoWayListNode {
public:
    TwoWayListNode* next;
    TwoWayListNode* previous;
    
    int value;

    TwoWayListNode(int value);

    TwoWayListNode* get_next(void);
    TwoWayListNode* get_previous(void);

    void set_next(TwoWayListNode* node);
    void set_previous(TwoWayListNode* node);
};

#endif