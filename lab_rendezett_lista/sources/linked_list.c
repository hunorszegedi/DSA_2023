//
// Created by Lenovo on 07/05/2023.
//

#include "linked_list.h"

Node *newNode(int new_data) {
    Node *newItem = (Node *) calloc(1, sizeof(Node)); //az 1-et igazabol felesleges odairni
    if (!newItem) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    newItem->data = new_data;
    newItem->next = NULL; //rendszerint NULL, mert nem tudjuk, hogy ki kovetkezik utana
    return newItem;
}

//ures-e a listank, van-e benne egyaltalan
//a head a lista elso elemere mutat
//ha ez null, akkor ures
bool isEmpty(Node *head) {
    return head == NULL;
}

/*konkretan a vegere szur, a vegehez csatolunk egy uj elemet
/cim szerint adom at a head-et, mert
/az elejen a head az null, de amikor bejon az elso elem, az lesz a head, ezert kell cim szerint atadni
/ugye ures lista eseten megvaltozik
*/
void insertAtEnd(Node **head_ref, int new_data) {
    //amikor a legelso elemet szurjuk be
    if (isEmpty(*head_ref)) {
        *head_ref = newNode(new_data);
        return;
    }
    Node *temp = *head_ref; //felveszunk egy segedvaltozot, hogy ne veszitsuk el a fejet
    //addig megyunk a listankon vegig, amig az utolso elemhez nem erunk
    while (temp->next != NULL) {
        temp = temp->next; //ez ugymond egy i++
    }
    temp->next = newNode(new_data);
}

void printList(Node *node) {
    Node *temp = node;
    while (temp != NULL) {
        printf("%i -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteFromBeginning(Node **head_ref) {
    if (isEmpty(*head_ref)) {
        printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
        return;
    }
    Node *temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void insertAfter(Node *prev_ref, int new_data) {
    if (prev_ref == NULL) {
        printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
        return;
    }
    Node *newItem = newNode(new_data);
    newItem->next = prev_ref->next;
    prev_ref->next = newItem;


}

void insertAtBeginning(Node **head_ref, int new_data) {
    Node *temp = newNode(new_data);
    if (isEmpty(*head_ref)) {
        *head_ref = temp;
        return;
    }
    temp->next = *head_ref;
    *head_ref = temp;
}

bool searchNode(Node *head_ref, int key) {
    Node *temp = head_ref;
    while (temp != NULL) {
        if (temp->data == key)return true;
        temp = temp->next;
    }
    return false;
}

void deleteFromEnd(Node **head_ref) {
    if (isEmpty(*head_ref)) {
        printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
        return;
    }
    if ((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }
    Node *temp = *head_ref;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteNode(Node **head_ref, int key) {
    if (isEmpty(*head_ref)) {
        printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
        return;
    }
    if ((*head_ref)->data == key) {
        deleteFromBeginning(head_ref);
        return;
    }
    Node *temp = (*head_ref)->next;
    Node *prev = (*head_ref);
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }
}

void sortLinkedList(Node *head_ref) {
    if (isEmpty(head_ref)) {
        printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
        return;
    }
    Node *first = head_ref;
    while (first != NULL) {
        Node *current = first->next;
        while (current != NULL) {
            if (first->data > current->data) {
                int aux = first->data;
                first->data = current->data;
                current->data = aux;
            }
            current = current->next;
        }
        first = first->next;
    }
}

void freeList(Node **head) {
    while (*head != NULL) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    *head = NULL;
}

void insert(Node **head_ref, int new_data) {
    Node *newItem, *last, *prev;
    newItem = newNode(new_data);
    if (isEmpty(*head_ref)) {
        *head_ref = newItem;
        return;
    }
    if ((*head_ref)->data >= newItem->data) {
        insertAtBeginning(head_ref, new_data);
        return;
    }
    last = *head_ref;
    prev = NULL;

    while (last != NULL && last->data <= new_data) {
        prev = last;
        last = last->next;
    }
    newItem->next = last;
    prev->next = newItem;
}
