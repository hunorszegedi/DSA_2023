//
// Created by Lenovo on 15/05/2023.
//

#ifndef HASITO_TABLAK_HASH_TABLE_H
#define HASITO_TABLAK_HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <constants.h>

// globaliskent felveszunk itt egy makrot
// tanacsos primszamot megadni kapacitasnak
#define CAPACITY 31 //globalis kapacitas per pill

//kulcs es data sem muszaj int legyen
typedef struct HashItem {
    int key;
    int data;
} HashItem;

//hash itemokbol allo tomb
typedef struct HashTable{
    HashItem *items;
    int size; //ennyi darab hely foglalt mar
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
void insert(HashTable *hashTable, int key, int data);

/**
* Deletes a data from the array
* @param hashTable
* @param key
* @param data
*/
void delete(HashTable *hashTable, int key);

/**
* Searches for a specific data with the given key
* @param hashTable
* @param key
* @return the position if it is present, -1 otherwise
*/
int search(HashTable hashTable, int key);

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


#endif //HASITO_TABLAK_HASH_TABLE_H
