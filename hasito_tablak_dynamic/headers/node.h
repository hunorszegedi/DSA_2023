//
// Created by Lenovo on 20/05/2023.
//

#ifndef HASITO_TABLAK_DYNAMIC_NODE_H
#define HASITO_TABLAK_DYNAMIC_NODE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <constants.h>
#include <string.h>

typedef struct HashItem {
    char key[20];
    char data[50];
} HashItem;

//Define a node
typedef struct Node {
    HashItem data;
    struct Node *next;
} Node;

/**
* Allocates memory for a new node
* @param new_data
* @return pointer to a new allocated node
*/
Node *newNode(HashItem new_data);

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
void insertFirst(Node **head_ref, HashItem new_data);

/**
* Delete the first node
* @param head_ref
*/
void deleteFromBeginning(Node **head_ref);

/**
* Delete a specific node
* @param head_ref
* @param key
*/
void deleteNode(Node **head_ref, char *key);

/**
* Searches for a specific node with value key
* @param head_ref
* @param key
* @return
*/
bool searchNode(Node *head_ref, char *key);

/**
* Print all elements of teh list
* @param node
*/
void printList(Node *node);

/**
 * Deallocates memory
 * @param head
 */
void freeList(Node **head);

void printNodeData(HashItem item);

#endif //HASITO_TABLAK_DYNAMIC_NODE_H
