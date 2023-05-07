//
// Created by Lenovo on 07/05/2023.
//

#ifndef LAB_LANCOLT_LISTA_LINKED_LIST_H
#define LAB_LANCOLT_LISTA_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <constants.h>
#include <stdbool.h>

//A LISTA ELSO ELEMET TUDNUNK KELL
///Define a node
typedef struct Node{
    int data; //informaciot hordozo adatmezo
    struct Node* next; //tudjuk a kovetkezo csomopontot
}Node;

/**
* Allocates memory for a new node
* @param new_data
* @return pointer to a new allocated node
*/
Node* newNode(int new_data);

/**
Checks if list is empty, head is NULL pointer
* @param head
* @return true/false
*/
bool isEmpty(Node *head);

/**
* Insertg new node at the end of the list
* @param head_ref
* @param new_data
*/
void insertAtEnd(Node** head_ref, int new_data);

/**
* Print all elements of teh list
* @param node
*/
void printList(Node* node);

/**
* Delete the first node
* @param head_ref
*/
void deleteFromBeginning(Node** head_ref);

/* Insert new node after a specific node
* @param prev_ref
* @param new_data
*/
void insertAfter(Node* prev_ref, int new_data);

/**
* Insert new node at the beginning of the list
* @param head_ref
* @param new_data
*/
void insertAtBeginning(Node** head_ref, int new_data);

/**
* Searches for a specific node with value key
* @param head_ref
* @param key
* @return
*/
bool searchNode(Node* head_ref, int key);

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
* Sort the values present in the list in ascending order
* @param head_ref
*/
void sortLinkedList(Node* head_ref);

/**
 * Deallocates memory
 * @param head
 */
void freeList(Node **head);

#endif //LAB_LANCOLT_LISTA_LINKED_LIST_H
