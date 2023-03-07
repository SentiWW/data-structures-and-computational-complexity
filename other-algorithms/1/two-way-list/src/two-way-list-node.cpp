#include "two-way-list-node.h"

TwoWayListNode::TwoWayListNode(int value) {
    previous = nullptr;
    next = nullptr;
    this->value = value; 
}

TwoWayListNode* TwoWayListNode::get_next(void) {
    return next;
}

void TwoWayListNode::set_next(TwoWayListNode* node) {
    next = node;
}

TwoWayListNode* TwoWayListNode::get_previous(void) {
    return previous;
}

void TwoWayListNode::set_previous(TwoWayListNode* node) {
    previous = node;
}