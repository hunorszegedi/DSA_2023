//
// Created by Lenovo on 24/04/2023.
//

#ifndef LAB6_LINKED_LIST_H
#define LAB6_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <constants.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/**
* Allocates memory for a new node
* @param new_data
* @return pointer to a new allocated node
*/
Node *newNode(int new_data);

/**
* Checks if list is empty, head is NULL pointer
* @param head
* @return true/false
*/
bool isEmpty(Node *head);

/**
* Insert new node at the beginning of the list
* @param head_ref
* @param new_data
*/
void insertAtBeginning(Node** head_ref, int new_data);

/**
* Insert new node after a specific node
* @param prev_ref
* @param new_data
*/
void insertAfter(Node* prev_ref, int new_data);

/**
* Insertg new node at the end of the list
* @param head_ref
* @param new_data
*/
void insertAtEnd(Node** head_ref, int new_data);

/**
* Delete the first node
* @param head_ref
*/
void deleteFromBeginning(Node** head_ref);

/**
* Delete the last node
* @param head_ref
*/
void deleteFromEnd(Node** head_ref);

/**
* Delete a specific node
* @param head_ref
* @param key
*/
void deleteNode(Node** head_ref, int key);

/**
* Searches for a specific node with value key
* @param head_ref
* @param key
* @return
*/
bool searchNode(Node* head_ref, int key);

/**
* Sort the values present in the list in ascending order
* @param head_ref
*/
void sortLinkedList(Node** head_ref);

/**
* Print all elements of teh list
* @param node
*/
void printList(Node* node);

#endif //LAB6_LINKED_LIST_H
