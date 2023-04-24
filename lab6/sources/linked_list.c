//
// Created by Lenovo on 24/04/2023.
//

#include "linked_list.h"

Node *newNode(int new_data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (!new_node) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    // insert the data
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

bool isEmpty(Node *head) {
    return head == NULL;
}

void insertAtBeginning(Node **head_ref, int new_data) {
    // Allocate memory to a node
    Node *new_node = newNode(new_data);
    new_node->next = (*head_ref);
    // Move head to new node
    (*head_ref) = new_node;
}

void insertAfter(Node *prev_ref, int new_data) {
    if (prev_ref == NULL) {
        printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
        return;
    }
    Node *new_node = newNode(new_data);
    new_node->next = prev_ref->next;
    prev_ref->next = new_node;
}

void insertAtEnd(Node **head_ref, int new_data) {
    Node *new_node = newNode(new_data);
    Node *last = *head_ref;
    if (isEmpty(*head_ref)) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;

}

void deleteFromBeginning(Node **head_ref) {
    if (isEmpty(*head_ref)) {
        printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
    }
    Node *temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void deleteFromEnd(Node **head_ref) {
    if (isEmpty(*head_ref)) {
        printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
        return;
    }
    Node *last = *head_ref, *prev;
    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    free(last);
}

void deleteNode(Node **head_ref, int key) {
    Node *temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
// Find the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
// If the key is not present
    if (temp == NULL) return;
// Remove the node
    prev->next = temp->next;
    free(temp);

}

bool searchNode(Node *head_ref, int key) {
    Node* current = head_ref;
    while (current != NULL) {
        if (current->data == key) return
                    true;
        current = current->next;
    }
    return false;
}

void sortLinkedList(Node **head_ref) {

}

void printList(Node *node) {
    while (node != NULL) {
        printf("%4d ", node->data);
        node = node->next;
    }
}
