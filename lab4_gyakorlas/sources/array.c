//
// Created by Lenovo on 12/03/2023.
//

#include "array.h"

void createIntArray(int capacity, IntArray *pArray) {
    //*pArray cim szerint adjuk at, mert meg fogjuk valtoztatni az erteket
    pArray->capacity = capacity; //kapacitasa egyenlo lesz azzal, amit megadunk
    pArray->size = 0; //kezdetben nincs egy elem sem benne
    pArray->elements = (int *) calloc(pArray->capacity, sizeof(int));
    if (!pArray->elements) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }

}

bool isFull(IntArray array) {
    return array.size == array.capacity;
}

bool isEmpty(IntArray array) {
    //. mert array valtozo, nem valtoztatunk meg semmit, nem jott cim szerint
    return array.size == 0; //if array.size == 0 return true, else return false
}

void printArray(IntArray array) {
    if (isEmpty(array)) {
        printf("Empty!\n");
        return;
    }
    printf("The elements of the array:\n");
    for (int i = 0; i < array.size; ++i) {
        printf("%i ", array.elements[i]);
    }
    printf("\n");
}

void insertFirst(IntArray *pArray, int item) {
    //1 2 3
    //4 1 2 3 lesz
    if (isFull(*pArray)) {
        printf(FULL_MESSAGE);
        return;
    }
    for (int i = pArray->size; i > 0; --i) {
        pArray->elements[i] = pArray->elements[i - 1];

    }
    pArray->elements[0] = item;
    pArray->size++;
}

void insertLast(IntArray *pArray, int item) {
    //1 2 3
    //1 2 3 4
    if (isFull(*pArray)) {
        printf(FULL_MESSAGE);
        return;
    }
    pArray->elements[pArray->size] = item;
    pArray->size++;
}

void insertAt(IntArray *pArray, int position, int item) {
    if (isFull(*pArray)) {
        printf(FULL_MESSAGE);
        return;
    }
    if (position < 0 || position > pArray->size) {
        printf(INVALID_POSITION_MESSAGE);
        return;
    }
    if (position == 0) {
        insertFirst(pArray, item);
        return;
    }
    if (position == pArray->size) {
        insertLast(pArray, item);
        return;
    }
    for (int i = pArray->size; i > position; --i) {
        pArray->elements[i] = pArray->elements[i - 1];
    }
    pArray->elements[position] = item;
    pArray->size++;
}

void deleteItemAt(IntArray *pArray, int position) {
    if (isEmpty(*pArray)) {
        printf(EMPTY_MESSAGE);
        return;
    }
    for (int i = position; i < pArray->size; ++i) {
        pArray->elements[i] = pArray->elements[i + 1];
    }
    pArray->elements[pArray->size - 1] = 0;
    pArray->size--;
}

int search(IntArray array, int item) {
    if (isEmpty(array)) {
        printf(EMPTY_MESSAGE);
        return -1;
    }
    for (int i = 0; i < array.size; ++i) {
        if (array.elements[i] == item) {      //strcmp
            return i;
        }
    }
    return -1;
}

bool update(IntArray *pArray, int position, int newItem) {
    if (isEmpty(*pArray)) {
        printf(EMPTY_MESSAGE);
        return false;
    }
    if (position < 0 || position >= pArray->size) {
        printf(INVALID_POSITION_MESSAGE);
        return false;
    }
    pArray->elements[position] = newItem;
    return true;
}

void deallocateIntArray(IntArray *pArray) {
    free(pArray->elements);
    pArray->capacity = pArray->size = 0;
    pArray = NULL;
}

int getItemAt(IntArray array, int position) {
    if(isEmpty(array)){
        printf(EMPTY_MESSAGE);
        return INT_MIN;
    }
    if(position < 0 || position >= array.size){
        return INT_MIN;
    }
    return array.elements[position];
}
