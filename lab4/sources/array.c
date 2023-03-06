//
// Created by Lenovo on 06/03/2023.
//

#include "array.h"

void createIntArray(int capacity, IntArray *pArray) {
    pArray->capacity = capacity;
    pArray->size = 0;
    pArray->elements = (int *) calloc(pArray->capacity, sizeof(int));
    if (pArray == NULL) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void printArray(IntArray array) {
    if (isEmpty(array)) {
        printf("Array is empty!\n");
        return;
    } else {
        printf("Capacity: %i\n", array.capacity);
        printf("Size: %i\n", array.size);
        printf("Elements:\n");
        for (int i = 0; i < array.size; ++i) {
            printf("\tElement %i: %i\n", i + 1, array.elements[i]);
        }
        printf("\n");
    }
}

bool isEmpty(IntArray array) {
    return array.size == 0; //igazsagerteke annak, hogy 0-e a size
}

bool isFull(IntArray array) {
    return array.size == array.capacity;
}

void insertFirst(IntArray *pArray, int item) {
    if (isFull(*pArray)) return;
//shifting the rest of the elements downwards
    for (int i = pArray->size - 1; i >= 0; --i) {
        pArray->elements[i + 1] = pArray->elements[i];
    }
    pArray->elements[0] = item;
    pArray->size++;
}

void insertLast(IntArray *pArray, int item) {
    if (isFull(*pArray)) return;
    pArray->elements[pArray->size++] = item;
}

void insertAt(IntArray *pArray, int position, int item) {
    if (isFull(*pArray)) return;
    if (position < 0 || position > pArray->size) {
        printf("ARRAY_POSITION_MESSAGE");
        return;
    }
    if (pArray->size == position) {
        insertLast(pArray, item);
        return;
    }
    if (position == 0) {
        insertFirst(pArray, item);
        return;
    }
    for (int i = pArray->size - 1; i >= position; --i) {
        pArray->elements[i + 1] = pArray->elements[i];
    }
    pArray->elements[position] = item;
    pArray->size++;

}


