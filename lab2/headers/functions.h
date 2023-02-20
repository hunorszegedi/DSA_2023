//
// Created by Lenovo on 18/02/2023.
//

#ifndef LAB1_GYAKORLAS_FUNCTIONS_H
#define LAB1_GYAKORLAS_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "constatns.h"
//declaration

int sum(int number1, int number2);

float minimum(float number1, float number2, float number3);

int *allocateMemoryForArray1(int n);

void allocateMemoryForArray2(int n, int **dpArray);

void readArray(int *pn, int **dpArray, const char *input);

void printArray(int n, int *pArray, const char *output);

void deallocateMemoryForArray(int **dpArray);

float avg(float number1, float number2);

float maximum(float number1, float number2, float number3);

void fillWithRandomNumbers(int n, int *pArray, int start, int end);

void printArrayInReverseOrder(int n, int *pArray, const char* output);


#endif //LAB1_GYAKORLAS_FUNCTIONS_H
