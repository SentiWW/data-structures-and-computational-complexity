#include "one-way-list-node.h"

OneWayListNode::OneWayListNode(int value) {
    next = nullptr;
    this->value = value; 
}

OneWayListNode* OneWayListNode::get_next(void) {
    return next;
}

void OneWayListNode::set_next(OneWayListNode* node) {
    next = node;
}