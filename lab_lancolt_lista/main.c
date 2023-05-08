#include "linked_list.h"

Node *createList(int number);

Node *addition(Node **first, Node **second);

int convertListToNumber(Node *node);

void addZeros(Node *node);

void deleteDigit(Node **node, int digit);

Node *createListOrai(int n);

int main() {

    int num1 = 22, num2 = 1342;
    Node *node1 = NULL, *node2 = NULL, *result = NULL;

    node1 = createList(num1);
    printList(node1);
    node2 = createList(num2);
    printList(node2);

    result = addition(&node1, &node2);
    printf("The sum of the two integers is: ");
    printList(result);

    int sum = convertListToNumber(result);
    printf("The sum of the two integers is: %i\n", sum);

    //minden paros elem utan szurjunk be egy 0-ast
    addZeros(result);
    printf("Adter adding 0 after each even item: ");
    printList(result);

    //Insert the same number to the beginning and the end of the list
    printf("Digit:");
    int digit;
    scanf("%i", &digit);

    insertAtBeginning(&result, digit);
    insertAtEnd(&result, digit);
    printf("After inserting %i digit as first and last node: ", digit);
    printList(result);

    //Search for a given digit
    printf("Search for %i: ", digit);
    if (searchNode(result, digit)) printf("is present\n");
    else printf(" is not present\n");

    //Delete all accurrences of a given digit
    deleteDigit(&result, digit);
    printf("Adter deleting all accurences of the given digit:");
    printList(result);


    //Delete last digit
    deleteFromEnd(&result);
    printf("After deleting last node:");
    printList(result);

    //Sort list
    sortLinkedList(result);
    printf("After sorting list item data: ");
    printList(result);

    //Deallocate memory
    freeList(&result);
    freeList(&node1);
    freeList(&node2);

    //n szam
    //n szam beolvasasas
    //lista letrehozasa
    //paros lista elejere
    //paratlan vegere
    //kiiratas
    //felszabaditas
    //
    int n;
    printf("Number:");
    scanf("%i", &n);
    Node *nodeOrai = NULL;
    nodeOrai = createListOrai(n);
    printList(nodeOrai);
    freeList(&nodeOrai);

    return 0;
}

Node *createListOrai(int n) {
    Node *head1 = NULL;
    int number;
    for (int i = 0; i < n; ++i) {
        scanf("%i", &number);
        if (number % 2 == 0) {
            insertAtBeginning(&head1, number);
        } else {
            insertAtEnd(&head1, number);
        }
    }
}

Node *createList(int number) {
    Node *head1 = NULL;
    while (number != 0) {
        insertAtEnd(&head1, number % 10);
        number /= 10;
    }
    return head1;
}

Node *addition(Node **first, Node **second) {
    Node *result = NULL;
    int mod = 0, div = 0;
    while (!isEmpty(*first) && !isEmpty(*second)) {
        mod = (div + (*first)->data + (*second)->data) % 10;
        div = (div + (*first)->data + (*second)->data) / 10;
        insertAtEnd(&result, mod);
        deleteFromBeginning(first);
        deleteFromBeginning(second);
    }
    while (!isEmpty(*first)) {
        mod = (div + (*first)->data) % 10;
        div = (div + (*first)->data) / 10;
        insertAtEnd(&result, mod);
        deleteFromBeginning(first);
    }
    while (!isEmpty(*second)) {
        mod = (div + (*second)->data) % 10;
        div = (div + (*second)->data) / 10;
        insertAtEnd(&result, mod);
        deleteFromBeginning(second);
    }
    if (div != 0) {
        insertAtEnd(&result, div);
    }
    *first = NULL;
    *second = NULL;
    return result;
}

int convertListToNumber(Node *node) {
    int sum = 0, p = 1;
    Node *temp = node;
    while (temp != NULL) {
        sum = p * temp->data + sum;
        p *= 10;
        temp = temp->next;
    }
    return sum;
}

void addZeros(Node *node) {
    Node *temp = node;
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            insertAfter(temp, 0);
            temp = temp->next;
        }
        temp = temp->next;
    }
}

void deleteDigit(Node **node, int digit) {
    while (searchNode(*node, digit)) {
        deleteNode(node, digit);
    }

}


