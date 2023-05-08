#include "linked_list.h"

int main() {

    int num1, num2;
    printf("Number1:");
    scanf("%i", &num1);
    printf("Number2:");
    scanf("%i", &num2);

    Node *node1 = NULL;
    Node *node2 = NULL;
    while (num1 != 0) {
        insertAtEnd(&(node1), num1 % 10);
        num1 /= 10;
    }
    printList(node1);
    printf("\n");
    while (num2 != 0) {
        insertAtEnd(&(node2), num2 % 10);
        num2 /= 10;
    }
    printList(node2);

    printf("\n");
    Node *nodeSum = NULL;
    int temp, m = 0;
    while (node1 != NULL || node2 != NULL) {
        temp = (m + node1->data + node2->data) % 10;
        m += (m + node1->data + node2->data) / 10;
        node1 = node1->next;
        node2 = node2->next;
        insertAtEnd(&(nodeSum), temp);
    }
    printList(nodeSum);
    return 0;
}
