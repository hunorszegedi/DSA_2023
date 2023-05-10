#include "linked_list.h"

Node *createList(int number);

int main() {

    int num1 = 34435431, num2 = 55351245;
    Node *node1 = NULL, *node2 = NULL;

    node1 = createList(num1);
    printList(node1);
    node2 = createList(num2);
    printList(node2);

    //Deallocate memory
    freeList(&node1);
    freeList(&node2);

    return 0;
}

Node *createList(int number) {
    Node *heah1 = NULL;
    while (number != 0) {
        insert(&heah1, number % 10);
        number /= 10;
    }
    return heah1;
}



