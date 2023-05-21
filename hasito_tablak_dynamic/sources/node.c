//
// Created by Lenovo on 20/05/2023.
//

#include "node.h"

Node *newNode(HashItem new_data) {
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

void insertFirst(Node **head_ref, HashItem new_data) {
    Node *temp = newNode(new_data);
    if (isEmpty(*head_ref)) {
        *head_ref = temp;
        return;
    }
    temp->next = *head_ref;
    *head_ref = temp;
}

void deleteFromBeginning(Node **head_ref) {
    if (isEmpty(*head_ref)) {
        printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
    }
    Node *temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void deleteNode(Node **head_ref, char *key) {
    if (isEmpty(*head_ref)) {
        printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
        return;
    }
    if (strcmp((*head_ref)->data.key, key) == 0) {
        deleteFromBeginning(head_ref);
        return;
    }
    Node *temp = (*head_ref)->next;
    Node *prev = (*head_ref);
    while (temp != NULL && strcmp(temp->data.key, key) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }
}

bool searchNode(Node *head_ref, char *key) {
    Node *temp = head_ref;
    while (temp != NULL) {
        if (strcmp(temp->data.key, key) == 0) return true;
        temp = temp->next;
    }
    return false;
}

void printNodeData(HashItem item) {
    printf("\t - key (%s): value (%s)\n", item.key, item.data);
}

void printList(Node *node) {
    Node *temp = node;
    while (temp != NULL) {
        printNodeData(temp->data);
        temp = temp->next;
    }
//    printf("NULL\n");
}

void freeList(Node **head) {
    Node *current = *head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}
