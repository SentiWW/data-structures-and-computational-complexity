#include "dynamic-array/dynamic-array.h"
#include "two-way-list/two-way-list.h"
#include "stdio.h"

void dynamic_array_tests(void) {
    DynamicArray* array = new DynamicArray();

    array->add(0);
    array->add(1);
    array->add(2);
    array->add(3);
    array->add(4);
    array->add(5);
    array->display();
}

void two_way_list_tests(void) {
    TwoWayList* list = new TwoWayList();

    list->add(0);
    list->add(1);
    list->add(2);
    list->add(3);
    list->add(4);
    list->add(5);
    list->add(6);
    list->display();

    printf("\n");

    list->remove(0);
    list->remove(6);
    list->display();
}

int main(void) {
    // dynamic_array_tests();
    two_way_list_tests();

    return 0;
}