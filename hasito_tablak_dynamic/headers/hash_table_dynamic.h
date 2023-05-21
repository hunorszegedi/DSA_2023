//
// Created by Lenovo on 20/05/2023.
//

#ifndef HASITO_TABLAK_DYNAMIC_HASH_TABLE_DYNAMIC_H
#define HASITO_TABLAK_DYNAMIC_HASH_TABLE_DYNAMIC_H

#include "node.h"

#define CAPACITY 13

//hash itemokbol allo tomb
typedef struct HashTable {
    Node *items[CAPACITY];
} HashTable;

static HashItem dummyData = {-1, 0}; //ures adat
//letrehozasnal feltoltjuk a dummyData-val
//-1 a key az uresnel

//hash fuggveny
//nem lehet ket ugyanolyan kulcs, egyedi kell legyen

/**
* Allocates memory for a hash table with defined SIZE
* @param pHashTable
*/
void createHashArray(HashTable *pHashTable);
//This should be only accessible in the .c file
//int hashCode(int key);
/**
* Inserts a new data to the hashArray
* @param hashTable
* @param key
* @param data
*/
void insert(HashTable *hashTable, char *key, char *data);

/**
* Deletes a data from the array
* @param hashTable
* @param key
* @param data
*/
void delete(HashTable *hashTable, char *key);

/**
* Searches for a specific data with the given key
* @param hashTable
* @param key
* @return the position if it is present, -1 otherwise
*/
bool search(HashTable hashTable, char *key);

/**
* Prints the content of the array to the standard input
* @param hashTable
*/
void display(HashTable hashTable);

/**
* Returns the number of elements present in the hashtable
* @param hashTable
* @return size
*/
int size(HashTable hashTable);

/**
* Deallocates memory
* @param pHashTable
*/
void destroyHashArray(HashTable *pHashTable);

#endif //HASITO_TABLAK_DYNAMIC_HASH_TABLE_DYNAMIC_H
