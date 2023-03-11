#include "two-way-list-node.h"

TwoWayListNode::TwoWayListNode(int value) {
    this->value = value;
    next = nullptr;
    previous = nullptr;
}

TwoWayListNode::~TwoWayListNode() {

}