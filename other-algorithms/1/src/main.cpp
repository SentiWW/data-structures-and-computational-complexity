#include "stdio.h"
#include "one-way-list.h"

int main(void) {
    OneWayList *list = new OneWayList();

    list->push_back(new OneWayListNode(3));
    list->push_back(new OneWayListNode(4));
    list->push_back(new OneWayListNode(5));
    list->push_back(new OneWayListNode(6));
    list->push_back(new OneWayListNode(7));
    list->push_back(new OneWayListNode(8));
    list->push_back(new OneWayListNode(9));
    list->push_front(new OneWayListNode(2));
    list->push_front(new OneWayListNode(1));
    list->push_front(new OneWayListNode(0));
    
    // Display list
    printf("Initial list state.\n");
    list->display_list();

    // Find element
    printf("Searching for element with value (1).\n");
    OneWayListNode* element = list->find(1);
    
    if (element == nullptr) {
        printf("Element not found.\n");
    } else {
        printf("Element found with value (%d).\n", element->value);
    }

    // Push at n-th position
    printf("Inserting element with value (3) at index 5.\n");
    printf("List before instert.\n");
    list->display_list();
    list->insert(new OneWayListNode(3), 5);
    printf("List after instert.\n");
    list->display_list();

    // Delete n-th element
    printf("Deleting element at index 2.\n");
    printf("List before deletion.\n");
    list->display_list();
    list->remove_node(2);
    printf("List after deletion.\n");
    list->display_list();

    return 0;
}