//
// Created by Lenovo on 06/03/2023.
//

#ifndef LAB4_ARRAY_H
#define LAB4_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <constants.h>

typedef struct IntArray {
    int capacity;
    int size;
    int *elements;
} IntArray;

/**
* Allocates memory for an array with a given capacity
* @param capacity
* @param pArray
*/
void createIntArray(int capacity, IntArray* pArray);

/**
* Prints all items in the array
* @param array
*/
void printArray(IntArray array);

/**
* Check whether the array is empty or not
* @param array
* @return true/false
*/
bool isEmpty(IntArray array);

/**
* Check whether the array is full or not
* @param array
* @return true/false
*/
bool isFull(IntArray array);

/**
* Inserts an item at the beginning of the array
* @param pArray
* @param item
*/
void insertFirst(IntArray* pArray, int item);

/**
* Inserts an item at the end of the array
* @param pArray
* @param item
*/
void insertLast(IntArray* pArray, int item);

/**
* Inserts an item at at a given position if the position is correct
* @param pArray
* @param item
*/
void insertAt(IntArray* pArray, int position, int item);


#endif //LAB4_ARRAY_H
