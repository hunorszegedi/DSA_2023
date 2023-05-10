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
typedef struct Node {
    int data; //informaciot hordozo adatmezo
    struct Node *next; //tudjuk a kovetkezo csomopontot
} Node;

/**
* Allocates memory for a new node
* @param new_data
* @return pointer to a new allocated node
*/
Node *newNode(int new_data);

/**
Checks if list is empty, head is NULL pointer
* @param head
* @return true/false
*/
bool isEmpty(Node *head);

/**
* Print all elements of teh list
* @param node
*/
void printList(Node *node);

/**
* Delete the first node
* @param head_ref
*/
void deleteFromBeginning(Node **head_ref);

/**
* Insert new node at the beginning of the list
* @param head_ref
* @param new_data
*/
void insertAtBeginning(Node **head_ref, int new_data);

/**
 * Deallocates memory
 * @param head
 */
void freeList(Node **head);


//uj
void insert(Node **head_ref, int new_data);

#endif //LAB_LANCOLT_LISTA_LINKED_LIST_H
